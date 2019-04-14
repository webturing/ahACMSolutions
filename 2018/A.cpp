#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
map<string, int> name;
vector<int> G[MAXN];
int in[MAXN];
int n, pos;

bool tupo() {
    int cnt = 0;
    queue<int> que;
    for (int i = 1; i <= pos; i++) {
        if (in[i] == 0)
            que.push(i);
    }
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        cnt++;
        for (int i = 0; i < G[now].size(); i++) {
            if (--in[G[now][i]] == 0)
                que.push(G[now][i]);
        }
    }
    return cnt == n;
}

int main() {
    int t;
    string a, b;
    cin >> t;
    while (t--) {
        pos = 0;
        cin >> n;
        for (int i = 1; i <= 2 * n; i++)
            G[i].clear();
        name.clear();
        memset(in, 0, sizeof(in));
        for (int i = 1; i <= n; i++) {
            cin >> a >> b;
            if (name[a] == 0)
                name[a] = ++pos;
            if (name[b] == 0)
                name[b] = ++pos;
            G[name[a]].push_back(name[b]);
            in[name[b]]++;
        }
        if (tupo())
            cout << "Passed" << endl;
        else
            cout << "Failed" << endl;
    }

    return 0;
}