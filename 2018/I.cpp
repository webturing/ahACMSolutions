#include <bits/stdc++.h>
using namespace std;

const int MXAN = 200 + 10;
int a[MXAN][MXAN];
int sum[MXAN][MXAN];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
                sum[i][j] = sum[i][j - 1] + a[i][j];
            }
        }
        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = i; j <= m; j++) {
                int tmp = 0;
                int len = 1;
                for (int line = 1; line <= n; line++) {
                    if (tmp != 0) {
                        if (a[line][i] == 1 && a[line][j] == 1) {
                            len++;
                        }
                        if (sum[line][j] - sum[line][i - 1] == j - i + 1) {
                            res = max(res, len * (j - i + 1));
                        }
                        if (a[line][i] == 0 || a[line][j] == 0) {
                            len = 1;
                            tmp = 0;
                        }
                    }
                    if (sum[line][j] - sum[line][i - 1] == j - i + 1)
                        tmp = 1;
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}