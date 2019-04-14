#include<bits/stdc++.h>

using namespace std;

int main() {
    char a[11];
    char b[100010];
    while (~scanf("%s", a)) {
        getchar();
        gets(b);
        int ans = 0;
        int lena = strlen(a);
        int lenb = strlen(b);
        for (int i = 0; i < lena; i++) {
            if (a[i] >= 'A' && a[i] <= 'Z')
                a[i] = a[i] - 'A' + 'a';
        }
        for (int i = 0; i < lenb; i++) {
            if (b[i] >= 'A' && b[i] <= 'Z')
                b[i] = b[i] - 'A' + 'a';
        }
        char *k;
        k = strstr(b, a);
        while (k != NULL) {
            ans++;
            k = strstr(k + lena, a);
        }
        printf("%d\n", ans);
    }
    return 0;
}