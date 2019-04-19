#include <cstdio>
#include <cstring>
#include <cstring>

int kase = 0, m, n, idx[1000][1000] = {0};
char tu[1000][1000];

void dfs(int r, int c, int id) {
    if (r < 0 || r >= n || c < 0 || c >= m) return;
    if (idx[r][c] > 0 || tu[r][c] == '#') return;
    idx[r][c] = id;
    /*
    for(int dr = -1; dr <= 1; dr++)
        for(int dc = -1; dc <= -1; dc++)
            if(dr != 0 || dc != 0) dfs(r+dr, c+dc, id); */
    dfs(r - 1, c, id);
    dfs(r + 1, c, id);
    dfs(r, c - 1, id);
    dfs(r, c + 1, id);
}

void doo() {
    memset(idx, 0, sizeof(idx));
    memset(tu, '%', sizeof(tu));
    ++kase;
    scanf("%d%d", &n, &m);
    for (int i = 0 + 1; i < n + 1; i++) {
        getchar();
        for (int j = 0 + 1; j < m + 1; j++)
            scanf("%c", &tu[i][j]);
    }
    m += 2;
    n += 2;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (idx[i][j] <= 0 && tu[i][j] != '#') dfs(i, j, ++cnt);
    char cc;
    if (cnt != 1) cc = 'A';
    else cc = 'H';
    printf("Case %d: %c\n", kase, cc);
}

int main() {
    //freopen("data.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--)
        doo();

    return 0;
}
