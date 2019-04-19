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
struct Num {
    int q, id;
};
TREE tree[400006];
int h[100005], n, re[100005];
Num num[100005];

bool cmp(const Num &a, const Num &b) {
    return a.q < b.q;
}

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

int main(int argc, char *argv[]) {
    //clock_t t1 = clock();
    //freopen( "b.in", "r", stdin );
    //freopen( "b_off.out", "w", stdout );
    int i, q;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", h + i);
    }
    build(0, n, 1);
    scanf("%d", &q);
    for (i = 0; i < q; ++i) {
        scanf("%d", &num[i].q);
        num[i].id = i;
    }
    sort(num, num + q, cmp);
    for (i = 0; i < q; ++i) {
        re[num[i].id] = query(num[i].q, 1).cm;
    }
    for (i = 0; i < q; ++i) printf("%d\n", re[i]);
    //clock_t t2 = clock();
    //printf( "%.3f ms\n", ( t2 - t1 ) * 1.0 / CLOCKS_PER_SEC * 1000.0 );
    return 0;
}
