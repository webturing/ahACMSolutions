#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    //freopen("D.in", "r", stdin);
    //freopen("D.out", "w", stdout);
    while (scanf("%d", &n) != EOF) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            sum ^= x;
        }
        if (sum) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
