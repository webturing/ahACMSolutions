#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 100010;

struct Node {
    int l, r, rt;
    int llen, rlen; // 区间左（右）端点开始的连续数列长度
    int mlen;       // 区间最长连续数列的长度
    long long lvalue, rvalue;   // 区间左（右）端点数列的值
    int len() {
        return r - l + 1;
    }
} seg[maxn << 2];

void build(int l, int r, int rt) {
    seg[rt].l = l;
    seg[rt].r = r;
    seg[rt].llen = seg[rt].rlen = seg[rt].mlen = seg[rt].len();
    seg[rt].lvalue = seg[rt].rvalue = 0;

    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, (rt << 1) | 1);
}

void pushDown(int rt) {
    if (seg[rt].mlen == seg[rt].len()) {
        int lch = rt << 1;
        int rch = (rt << 1) | 1;

        seg[lch].llen = seg[lch].rlen = seg[lch].mlen = seg[lch].len();
        seg[lch].lvalue = seg[rt].lvalue;
        seg[rch].llen = seg[rch].rlen = seg[rch].mlen = seg[rch].len();
        seg[rch].rvalue = seg[rt].rvalue;
    }
}

void pushUp(int rt) {
    int lch = rt << 1;
    int rch = (rt << 1) | 1;

    seg[rt].lvalue = seg[lch].lvalue;
    seg[rt].rvalue = seg[rch].rvalue;
    seg[rt].llen = seg[lch].llen;
    seg[rt].rlen = seg[rch].rlen;
    seg[rt].mlen = max(seg[lch].mlen, seg[rch].mlen);

    if (seg[lch].len() == seg[lch].llen && seg[rch].lvalue == seg[lch].rvalue) {
        seg[rt].llen += seg[rch].llen;
    }
    if (seg[rch].len() == seg[rch].rlen && seg[lch].rvalue == seg[rch].lvalue) {
        seg[rt].rlen += seg[lch].rlen;
    }
    if (seg[lch].rvalue == seg[rch].lvalue) {
        seg[rt].mlen = max(seg[rt].mlen, seg[lch].rlen + seg[rch].llen);
    }
}

void update(int l, int r, int rt, long long d) {
    if (l > r) {
        return;
    }
    if (l == seg[rt].l && r == seg[rt].r) {
        if (seg[rt].mlen == seg[rt].len()) {
            seg[rt].lvalue += d;
            seg[rt].rvalue += d;
            return;
        }
    }
    pushDown(rt);
    int mid = (seg[rt].l + seg[rt].r) / 2;
    int lch = rt << 1;
    int rch = (rt << 1) | 1;
    if (r <= mid) {
        update(l, r, lch, d);
    } else if (l > mid) {
        update(l, r, rch, d);
    } else {
        update(l, mid, lch, d);
        update(mid + 1, r, rch, d);
    }
    pushUp(rt);
}

int query(int l, int r, int rt) {
    if (l > r) {
        return 0;
    }
    if (l == seg[rt].l && r == seg[rt].r) {
        return seg[rt].mlen;
    }
    pushDown(rt);

    int lch = (rt << 1);
    int rch = (rt << 1) | 1;
    int mid = (seg[rt].l + seg[rt].r) >> 1;

    if (r <= mid) {
        return query(l, r, lch);
    } else if (l > mid) {
        return query(l, r, rch);
    } else {
        int mlen;
        mlen = max(query(l, mid, lch), query(mid + 1, r, rch));
        if (seg[lch].rvalue == seg[rch].lvalue) {
            mlen = max(mlen, min(seg[lch].rlen, mid - l + 1) + min(seg[rch].llen, r - mid));
        }
        return mlen;
    }
}

int main() {
    //freopen("W.等差数列.in", "r", stdin);
    //freopen("W.等差数列.out", "w", stdout);
    int n, m;
    char op[10];
    int L, R;
    int A, D;
    int tcase = 0;
    while (scanf("%d%d", &n, &m) != EOF) {
        tcase++;
        printf("Case #%d:\n", tcase);
        build(1, n - 1, 1);
        for (int i = 0; i < m; ++i) {
            scanf("%s", op);
            if (op[0] == 'A') {
                scanf("%d%d%d%d", &L, &R, &A, &D);
                if (L != 0) {
                    update(L, L, 1, A);
                }
                if (L + 1 <= R) {
                    update(L + 1, R, 1, D);
                }
                if (R != n - 1) {
                    update(R + 1, R + 1, 1, -(A + (R - 1) * D));
                }
            } else {
                scanf("%d%d", &L, &R);
                printf("%d\n", query(L + 1, R, 1) + 1);
            }
        }
    }
    return 0;
}
