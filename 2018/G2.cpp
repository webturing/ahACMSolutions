#include<bits/stdc++.h>

using namespace std;
const int maxn = 5000;
double f[maxn + 1][3 * maxn + 10];

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int n, h;
        cin >> n >> h;
        if (h < 3 * n) cout << "1.000000" << '\n';
        else if (h > 6 * n) cout << "0.000000" << '\n';
        else {
            h -= 3 * n;
            memset(f, 0, sizeof(f));
            f[1][0] = 0.25;
            f[1][1] = 0.25;
            f[1][2] = 0.25;
            f[1][3] = 0.25;
            for (int i = 2; i <= n; i++) {
                for (int j = 0; j <= 3 * i; j++) {
                    f[i][j] = 0;
                    for (int k = 0; k <= min(3, j); k++) {
                        f[i][j] += 0.25 * f[i - 1][j - k];
                    }
                }
                copy(f[i], f[i] + 3 * i + 1, ostream_iterator<double>(cout, " "));
                cout << endl;
            }
            cout << fixed << setprecision(6) << accumulate(f[n] + h, f[n] + 3 * n + 1, 0.0) << '\n';
        }
    }
    return 0;
}
