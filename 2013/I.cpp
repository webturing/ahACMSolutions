#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
int map[51][51], t[51][51];
long long s[51][51];
int dir[4][2] = {{-1, 0},
                 {1,  0},
                 {0,  -1},
                 {0,  1}};
int n, m;

struct pp {
    int x, y;
};
queue<pp> que;
int flag[99][99];

void bfs() {

    pp a, b;
    int dx, dy, i, spend;
    a.x = n - 1;
    a.y = m - 1;
    t[n - 1][m - 1] = map[n - 1][m - 1];
    que.push(a);
    while (!que.empty()) {
        b = que.front();
        que.pop();
        for (i = 0; i < 4; i++) {
            dx = b.x + dir[i][0];
            dy = b.y + dir[i][1];
            if (dx >= 0 && dx < n && dy >= 0 && dy < m) {
                spend = t[b.x][b.y] + map[dx][dy];
                if (t[dx][dy] == -1 || spend < t[dx][dy]) {
                    a.x = dx;
                    a.y = dy;
                    t[dx][dy] = spend;
                    que.push(a);
                }
            }
        }
    }
}

long long dfs(int x, int y) {
    int i;
    if (s[x][y] > -1)
        return s[x][y];
    if (x == n - 1 && y == m - 1)
        return 1;
    flag[x][y]++;
    s[x][y] = 0;
    for (i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
            if (t[x][y] > t[xx][yy]) {
                s[x][y] += dfs(xx, yy);
            }
        }
    }
    return s[x][y];
}

int main() {
    int i, j;
    while (cin >> n >> m) {
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++) {
                cin >> map[i][j];
                t[i][j] = -1;
            }
        while (!que.empty()) que.pop();
        memset(s, -1, sizeof(s));
        memset(flag, 0, sizeof(flag));
        bfs();
        dfs(0, 0);
        cout << s[0][0] << endl;
    }
    return 0;
}

