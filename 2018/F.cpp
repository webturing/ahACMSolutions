#include <bits/stdc++.h>

using namespace std;
#define MAXN 205

int n, m;
bool G[MAXN][MAXN];
int idx[MAXN][MAXN];
int iMax;

void dfs(int r, int c, int id, int &cnt) {
    if (r < 0 || r >= n || c < 0 || c >= m) return;
    if (G[r][c] == 0 || idx[r][c] > 0) return;
    idx[r][c] = id;
    cnt++;
    dfs(r - 1, c, id, cnt);
    dfs(r, c + 1, id, cnt);
    dfs(r + 1, c, id, cnt);
    dfs(r, c - 1, id, cnt);
}

void doo() {
    memset(G, 0, sizeof(G));
    memset(idx, 0, sizeof(idx));
    iMax = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> G[i][j];
    int id = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            if (G[i][j] == 1 && idx[i][j] == 0) dfs(i, j, ++id, cnt);
            if (cnt > iMax) iMax = cnt;
        }
    //cout << "id=" << id << endl;
    cout << iMax << endl;

}

int main() {
    //freopen("data.in", "r", stdin);
    int T;
    cin >> T;
    while (T--)
        doo();
    return 0;
}
