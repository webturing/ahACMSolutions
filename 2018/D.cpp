#include <bits/stdc++.h>

#define ll long long
#define maxn 100000
using namespace std;


int dp[maxn + 5], a[maxn + 5], res[maxn + 5];

int main() {
    int t, l, r, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        res[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = 1;
            res[i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (a[j] < a[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            if (i != 1)
                res[i] = max(res[i - 1], dp[i]);
        }
        for (int k = 1; k <= m; k++) {
            cin >> l >> r;
            cout << res[r] - res[l - 1] << " ";
        }
        cout << endl;
    }
    return 0;
}
 