#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        n = n * m;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        while (q--) {
            int h;
            cin >> h;
            int time = upper_bound(a, a + n, h) - a;
            cout << n - time << endl;
        }
    }
    return 0;
}

