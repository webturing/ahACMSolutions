#include <stdio.h>
#include <algorithm>
#include <time.h>

using namespace std;

struct Node {
    int lm, cm, rm;

    Node() {}

    Node(int l, int c, int r) : lm(l), cm(c), rm(r) {}
};

struct TREE {
    int l, r, min, max;
    Node node;
};
TREE tree[400006];
int h[100005], n, re[100005];

inline int _min(int a, int b) {
    if (a > b) return b;
    return a;
}

inline int _max(int a, int b) {
    if (a > b) return a;
    return b;
}

void build(int l, int r, int id) {
    tree[id].l = l;
    tree[id].r = r;
    tree[id].node.cm = 1;
    tree[id].node.lm = 1;
    tree[id].node.rm = 1;
    int mid = (l + r) >> 1;
    if (mid == l) {
        tree[id].min = h[l];
        tree[id].max = h[l];
        return;
    }
    build(l, mid, id << 1);
    build(mid, r, (id << 1) ^ 1);
    tree[id].max = _max(tree[id << 1].max, tree[(id << 1) ^ 1].max);
    tree[id].min = _min(tree[id << 1].min, tree[(id << 1) ^ 1].min);
    return;
}

inline Node up(const Node &a, const Node &b) {
    return Node(a.lm, a.cm + b.cm - (a.rm & b.lm), b.rm);
}

const Node &query(int h, int id) {
    if (h < tree[id].min) {
        return tree[id].node;
    }
    if (h >= tree[id].max) {
        tree[id].min = h + 1;
        tree[id].node.cm = 0;
        tree[id].node.lm = 0;
        tree[id].node.rm = 0;
        return tree[id].node;
    }
    tree[id].node = up(query(h, id << 1), query(h, (id << 1) ^ 1));
    if (tree[id << 1].min > tree[id << 1].max) {
        tree[id].min = tree[(id << 1) ^ 1].min;
    } else if (tree[(id << 1) ^ 1].min > tree[(id << 1) ^ 1].max) {
        tree[id].min = tree[id << 1].min;
    } else {
        tree[id].min = _min(tree[id << 1].min, tree[(id << 1) ^ 1].min);
    }
    return tree[id].node;
}

int bin_search(int l, int r, int x) {
    int mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (h[mid] > x) r = mid;
        else l = mid + 1;
    }
    return re[l - 1];
}

int main(int argc, char *argv[]) {
    //clock_t t1 = clock();
    //freopen( "b.in", "r", stdin );
    //freopen( "b_on.out", "w", stdout );
    int i, q;
    scanf("%d", &n);
    h[0] = 0;
    for (i = 1; i <= n; ++i) {
        scanf("%d", h + i);
    }
    build(1, n + 1, 1);
    sort(h + 1, h + n + 1);
    int j;
    for (i = 2, j = 1; i <= n; ++i) {
        if (h[i] != h[j]) {
            ++j;
            if (j != i) h[j] = h[i];
        }
    }
    re[0] = 1;
    for (i = 1; i <= j; ++i) {
        re[i] = query(h[i], 1).cm;
    }
    scanf("%d", &q);
    int x;
    ++j;
    while (q--) {
        scanf("%d", &x);
        printf("%d\n", bin_search(0, j, x));
    }
    //clock_t t2 = clock();
    //printf( "%.3f ms\n", ( t2 - t1 ) * 1.0 / CLOCKS_PER_SEC * 1000.0 );
    return 0;
}