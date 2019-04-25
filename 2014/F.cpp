#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        if (n % 2 == 0) {
            double x = (a[n / 2] + a[(n / 2) - 1]) / 2.;
            cout << fixed << setprecision(2) << x << endl;
        } else {
            cout << fixed << setprecision(2) << double(a[n / 2]) << endl;
        }
    }
    return 0;
}