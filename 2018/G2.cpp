#include<bits/stdc++.h>

using namespace std;
const int maxn = 5000;
double f[2][maxn + 10];

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int n, h;
        cin >> n >> h;
        if (h <= 3 * n) cout << "0.000000" << endl;
        else if (h > 6 * n) cout << "1.000000" << endl;
        else {
            h -= 3 * n;
            memset(f, 0, sizeof(f));
            f[1][0] = 1;
            f[1][1] = 0.75;
            f[1][2] = 0.5;
            f[1][3] = 0.25;
            for (int i = 2; i <= n; i++) {
                for (int j = 0; j <= 3 * i; j++) {
                    f[i][j] = 0;
                    for (int k = 0; k <= j && k <= 3; k++) {
                        f[i][j] += f[(i + 1) % 2][j - k] * 0.25;
                    }
                }
            }
            cout << fixed << setprecision(6) << f[n][h] << endl;
        }
    }
    return 0;
}
