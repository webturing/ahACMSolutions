#include <bits/stdc++.h>

using namespace std;
#define MAX 100005

vector<int> G[MAX];
int du[MAX];
int m, id;
map<string, int> hmap;

int TopSort() {
    int tot = 0;
    priority_queue<int> que;
    for (int i = 0; i <= id; i++)
        if (du[i] == 0) que.push(i);
    while (!que.empty()) {
        int x = que.top();
        que.pop();
        tot++;
        for (int i = 0; i < G[x].size(); i++) {
            int u = G[x][i];
            du[u]--;
            if (!du[u])
                que.push(u);
        }
    }
    if (tot == id + 1) return true;
    return false;
}

void doo() {
    id = -1;
    memset(du, 0, sizeof(du));
    hmap.clear();
    cin >> m;
    for (int i = 0; i <= m; i++)
        G[i].clear();
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        if (hmap.count(a) == 0)
            hmap.insert(pair<string, int>(a, ++id));
        if (hmap.count(b) == 0)
            hmap.insert(pair<string, int>(b, ++id));
        G[hmap[b]].push_back(hmap[a]);
        du[hmap[a]]++;
    }
    cout << (TopSort() ? "Passed" : "Failed") << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--)
        doo();

    return 0;
}

/**
2
8
client.cpp client.h
client.h server.h
server.cpp server.h
server.h common.h
client.h common.h
common.cpp common.h
common.h gtest.h
common.h glog.h
4
work.cpp client.cpp
client.cpp server.cpp
server.cpp adhoc.cpp
adhoc.cpp work.cpp
*/