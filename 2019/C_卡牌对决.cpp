#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[50004];
int b[50004], p, pn;
int f[100005];

int main() {
    scanf("%d", &n);
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        if (i < n / 2) f[a[i]] = 1;
        else f[a[i]] = 2;
    }
    int sum = 0;
    for (int i = 2 * n; i > 0; i--) {
        if (f[i] == 0) b[pn++] = i;
        else if (f[i] == 1) {
            if (p < pn) {
                sum++;
                f[b[p++]] = -1;
            }
        } else continue;
    }
    p = pn = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (f[i] == 0) b[pn++] = i;
        else if (f[i] == 2) {
            if (p < pn) {
                sum++;
                f[b[p++]] = -1;
            }
        } else continue;
    }
    cout << sum;
    return 0;
}