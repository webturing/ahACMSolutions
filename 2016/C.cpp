#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Arrow {
    int base, add;

    void get() {
        int a, b;
        scanf("%d%*d%d", &a, &b);
        base = b;
        add = a - b;
    }

    bool operator<(const Arrow &b) const { return add < b.add; }
} arr[1005];

int main() {
    int T, n;
    for (scanf("%d", &T); T--;) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) arr[i].get();
        sort(arr, arr + n);
        int t;
        scanf("%d", &t);
        for (int i = 0; i < n; i++) t -= arr[i].base;
        if (t < 0) {
            puts("Oh,my god!");
            continue;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (t >= arr[i].add) {
                t -= arr[i].add;
                ans++;
            } else
                break;
        }
        printf("%d\n", ans);
    }
    return 0;
}