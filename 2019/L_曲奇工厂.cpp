#include <bits/stdc++.h>

using namespace std;
int n, c, s, ans;
int a[10], b[10];
int f[5] = {0, 1, 2, 3, 4};

int main() {
    cin >> n >> c >> s;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    ans = 0x3f3f3f3f;
    do {
        int i, j, k, t, w, val;
        ans = min(ans, (c + s - 1) / s);
        for (j = f[i = 0], t = val = 0, w = s; i < n; ++i, j = f[i]) {
            k = max(0, a[j] - val + w - 1) / w;
            t += k, val += k * w - a[j], w += b[j];
            ans = min(ans, t + max(0, (c - val + w - 1) / w));
        }

    } while (next_permutation(f, f + n));
    cout << ans << endl;
    return 0;
}