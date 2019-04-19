#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;
#define ONLINE_JUDGE
const int inf = 0x7fffffff;
struct Edge {
    int from, to, nxt;
} e[505];
int idx, n, a, b, d[205], head[205];

void addedge(int from, int to) {
    e[idx].from = from;
    e[idx].to = to;
    e[idx].nxt = head[from];
    head[from] = idx++;
}

void Bellman_Ford() {
    int i, j;
    for (i = 1; i <= n; ++i) {
        d[i] = inf;
    }
    d[a] = 0;
    for (i = 1; i <= n - 1; ++i) {
        for (j = 0; j < idx; ++j) {
            if (d[e[j].from] != inf) {
                if (d[e[j].to] > d[e[j].from] + 1) {
                    d[e[j].to] = d[e[j].from] + 1;
                }
            }
        }
    }
    if (d[b] == inf) printf("-1\n");
    else printf("%d\n", d[b]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("G.in", "r", stdin);
 freopen("G.out", "w", stdout);
#endif
    int i, tmp;
    while (scanf("%d", &n) != EOF) {
        if (!n) break;
        scanf("%d%d", &a, &b);
        idx = 0;
        memset(head, -1, sizeof(head));
        for (i = 1; i <= n; ++i) {
            scanf("%d", &tmp);
            if (i - tmp > 0) addedge(i, i - tmp);
            if (i + tmp <= n) addedge(i, i + tmp);
        }
        Bellman_Ford();
    }
    return 0;
}