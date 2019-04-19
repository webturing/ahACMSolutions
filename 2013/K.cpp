#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<cassert>
#include<cstring>
#include<iomanip>

using namespace std;
const int inf = 0x3f3f3f3f;
const double oo = 10e9;
const double eps = 10e-9;
const double pi = acos(-1.0);
const int maxn = 100001;
vector<int> g[maxn];
double s[maxn];
double go[maxn];
double back[maxn];
double sum[maxn];
int n;
int t[maxn];
bool vis[maxn];

void df1(int now) {
    int to;
    vis[now] = true;
    for (int i = 0; i < g[now].size(); i++) {
        to = g[now][i];
        if (!vis[to]) {
            t[to] = now;
            df1(to);
        }
    }
    return;
}

void df2(int now) {
    int to;
    if (t[now] != -1) go[now] = 1.0 / s[now];
    else go[now] = 0.0;
    sum[now] = 0.0;
    for (int i = 0; i < g[now].size(); i++) {
        to = g[now][i];
        if (to != t[now]) {
            df2(to);
            go[now] += go[to] / (s[now] - 1.0);
            sum[now] += go[to];
        }
    }
    return;
}

void df3(int now) {
    int to;
    for (int i = 0; i < g[now].size(); i++) {
        to = g[now][i];
        if (to != t[now]) {
            back[to] = 1.0 / s[now];
            back[to] += back[now] / (s[now] - 1.0);
            back[to] += (sum[now] - go[to]) / (s[now] - 1.0);
            df3(to);
        }
    }
    return;
}

double start() {
    for (int i = 1; i <= n; i++) {
        s[i] = g[i].size();
    }
    t[1] = -1;
    memset(vis, false, sizeof(vis));
    df1(1);
    df2(1);
    back[1] = 0.0;
    df3(1);
    double re = 0.0;
    if (g[1].size() == 1) {
        re = go[g[1][0]];
    }
    for (int i = 2; i <= n; i++) {
        if (g[i].size() == 1) {
            re = max(re, back[i]);
        }
    }
    return re;
}

int main() {
    while (cin >> n) {
        if (!n) return 0;
        for (int i = 0; i <= n; i++)
            g[i].clear();
        int x, y;
        for (int i = 1; i <= n - 1; i++) {
            //cin>>x>>y;
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        printf("%.3lf\n", start());
    }
    return 0;
}

