#include<bits/stdc++.h>

using namespace std;
int n, m;
char cat[1005][1005], str[105][35];
int nxt[1001][1001][26];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", cat[i] + 1);
        int len = strlen(cat[i] + 1);
        for (int j = 1; j <= len; j++) {
            cat[i][j] = tolower(cat[i][j]);
        }
        for (int j = len; j >= 1; j--) {
            if (j == len) {
                for (int k = 0; k <= 25; k++) {
                    nxt[i][j][k] = len + 1;
                }
            }
            for (int k = 0; k <= 25; k++) {
                nxt[i][j - 1][k] = nxt[i][j][k];
            }
            nxt[i][j - 1][cat[i][j] - 'a'] = j;
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%s", str[i] + 1);
        int len = strlen(str[i] + 1);
        for (int j = 1; j <= len; j++) {
            str[i][j] = tolower(str[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int ans = 0, catlen = strlen(cat[i] + 1);
        for (int j = 1; j <= m; j++) {
            int p = 0, flag = 1;
            int slen = strlen(str[j] + 1);
            for (int k = 1; k <= slen; k++) {
                p = nxt[i][p][str[j][k] - 'a'];
                if (p > catlen) {
                    flag = 0;
                    break;
                }
            }
            if (flag)ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}