#include"bits/stdc++.h"
using namespace std;
struct node {
    int v, pi, qi;
};
vector<node> v[10005], v1[10005];
vector<pair<int, int> > v2[10005];

struct edge {
    int id, num;

    friend bool operator<(const edge a, const edge b) {
        return a.num > b.num;
    }
};

int n, m;
const int INF = 0x3f3f3f3f;
int dis1[10005], dis2[10005], dis3[10005], visit[10005];

void dijk1(int s) {
    priority_queue<edge> q;
    memset(visit, 0, sizeof(visit));
    memset(dis1, INF, sizeof(dis1));
    dis1[s] = 0;
    q.push(edge{s, 0});
    while (!q.empty()) {
        edge top = q.top();
        q.pop();
        if (visit[top.id])continue;
        visit[top.id] = 1;
        for (int i = 0; i < v[top.id].size(); i++) {
            int dv = v[top.id][i].v;
            int dpi = v[top.id][i].pi;
            if (dis1[dv] > dis1[top.id] + dpi) {
                dis1[dv] = dis1[top.id] + dpi;
                q.push(edge{dv, dis1[dv]});
            }
        }
    }
}

void dijk2(int s) {
    priority_queue<edge> q;
    memset(visit, 0, sizeof(visit));
    memset(dis2, INF, sizeof(dis2));
    dis2[s] = 0;
    q.push(edge{s, 0});
    while (!q.empty()) {
        edge top = q.top();
        q.pop();
        for (int i = 0; i < v[top.id].size(); i++) {
            int dv = v[top.id][i].v;
            int dqi = v[top.id][i].qi;
            if (dis2[dv] > dis2[top.id] + dqi) {
                dis2[dv] = dis2[top.id] + dqi;
                q.push(edge{dv, dis2[dv]});
            }
        }
    }
}

void dijk3(int s) {
    priority_queue<edge> q;
    memset(visit, 0, sizeof(visit));
    memset(dis3, INF, sizeof(dis3));
    dis3[s] = 0;
    q.push(edge{s, 0});
    while (!q.empty()) {
        edge top = q.top();
        q.pop();
        if (visit[top.id])continue;
        visit[top.id] = 1;
        for (int i = 0; i < v2[top.id].size(); i++) {
            pair<int, int> t = v2[top.id][i];
            int dv = t.first;
            int dw = t.second;
            if (dis3[dv] > dis3[top.id] + dw) {
                dis3[dv] = dis3[top.id] + dw;
                q.push(edge{dv, dis3[dv]});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v[b].push_back(node{a, c, d});
        v1[a].push_back(node{b, c, d});
    }
    dijk1(n);
    dijk2(n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < v1[i].size(); j++) {
            node t = v1[i][j];
            if (dis1[i] < dis1[t.v] + t.pi)ans++;
            if (dis2[i] < dis2[t.v] + t.qi)ans++;
            v2[i].push_back(make_pair(t.v, ans));
            ans = 0;
        }
    }
    dijk3(1);
    cout << dis3[n];
    return 0;
}