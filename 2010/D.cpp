#include<bits/stdc++.h>

using namespace std;

int main() {
    int a[100][6], i, n, k, pan, h;
    while (scanf("%d", &n) != EOF) {
        pan = 1;
        k = 0;
        while (k < n) {
            for (i = 0; i < 6; i++)
                scanf("%d", &a[k][i]);
            if (k > 0) {
                if (((a[k][0] == a[k - 1][0] && a[k][2] == a[k - 1][2]) ||
                     (a[k][0] == a[k - 1][2] && a[k][2] == a[k - 1][0]))
                    && ((a[k][1] == a[k - 1][1] && a[k][3] == a[k - 1][3]) ||
                        (a[k][1] == a[k - 1][3] && a[k][3] == a[k - 1][1])))
                    continue;
                pan = 0;
            }
            k++;
        }
        if (pan == 1)
            printf("yes\n");
        if (pan == 0)
            printf("no\n");
    }
    return 0;
}