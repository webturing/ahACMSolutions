#include<bits/stdc++.h>

#define lowbit(x) ((-x)&(x))
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
struct node {
    int id, r, t;
};
vector<int> g[maxn];
node a[maxn];
int in[maxn], out[maxn], n, root, cnt;
ll c[maxn], ans[maxn];

bool cmp(node a, node b) {
    return a.r < b.r;
}

void dfs(int x) {
    in[x] = ++cnt;
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        dfs(y);
    }
    out[x] = cnt;
}

void add(int x, int t) {
    for (int i = x; i <= n; i += lowbit(i)) {
        c[i] += t;
    }
}

ll query(int x) {
    ll res = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) {
        res += c[i];
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u;
        scanf("%d%d%d", &u, &a[i].r, &a[i].t);
        a[i].id = i;
        if (u > 0) g[u].push_back(i);
        else root = i;
    }
    dfs(root);
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (a[j + 1].r == a[i].r)j++;
        for (int k = i; k <= j; k++) {
            ans[a[k].id] = query(out[a[k].id]) - query(in[a[k].id]);
        }
        for (int k = i; k <= j; k++) {
            add(in[a[k].id], a[k].t);
        }
        i = j;
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}