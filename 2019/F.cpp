#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

#define REP(i, a, n) for(int i=a;i<=n;++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, a, b, S, T;
char s[55][55];

struct edge {
    int v, next;
    ll w;

    edge() {}

    edge(int v, int next, ll w) : v(v), w(w), next(next) {}
} e[N];

int head[N], dep[N], vis[N], cur[N], cnt = 1;
queue<int> Q;

pii get(int t) {
    int x = (t - 1) / m + 1, y = (t - 1) % m + 1;
    return pii(x, y);
}

void add(int u, int v, ll w) {
    e[++cnt] = edge(v, head[u], w);
    head[u] = cnt;
    e[++cnt] = edge(u, head[v], 0);
    head[v] = cnt;
}

int bfs() {
    REP(i, 1, T) dep[i] = INF, vis[i] = 0, cur[i] = head[i];
    dep[S] = 0, Q.push(S);
    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        for (int i = head[u]; i; i = e[i].next) {
            if (dep[e[i].v] > dep[u] + 1 && e[i].w) {
                dep[e[i].v] = dep[u] + 1;
                Q.push(e[i].v);
            }
        }
    }
    return dep[T] != INF;
}

ll dfs(int x, ll w) {
    if (x == T) return w;
    ll used = 0;
    for (int i = cur[x]; i; i = e[i].next) {
        cur[x] = i;
        if (dep[e[i].v] == dep[x] + 1 && e[i].w) {
            int flow = dfs(e[i].v, min(w - used, e[i].w));
            if (flow) {
                used += flow;
                e[i].w -= flow;
                e[i ^ 1].w += flow;
                if (used == w) break;
            }
        }
    }
    return used;
}

ll dinic() {
    ll ans = 0;
    while (bfs()) ans += dfs(S, 1e18);
    return ans;
}

int id(int x, int y) {
    return (x - 1) * m + y;
}

int main() {
    cin >> n >> m >> a >> b;
    REP(i, 1, n) cin >> s[i] + 1;
    S = n * m + 1, T = S + 1;
    REP(i, 1, n) REP(j, 1, m) {
            if (s[i][j] == '.') add(S, id(i, j), b);
            else add(id(i, j), T, b);
            if (i != n) {
                if (s[i][j] == '.' && s[i + 1][j] == '#') add(id(i, j), id(i + 1, j), a);
                else add(id(i + 1, j), id(i, j), a);
                if (s[i][j] == s[i + 1][j]) add(id(i, j), id(i + 1, j), a);
            }
            if (j != m) {
                if (s[i][j] == '.' && s[i][j + 1] == '#') add(id(i, j), id(i, j + 1), a);
                else add(id(i, j + 1), id(i, j), a);
                if (s[i][j] == s[i][j + 1]) add(id(i, j), id(i, j + 1), a);
            }
        }
    cout << dinic() << endl;
    return 0;
}