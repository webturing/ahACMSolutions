#include <bits/stdc++.h>

using namespace std;
const int N = 3e2 + 5;
char s[N];
int n, ans;

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);

    s[0] = '0';
    for (int i = 2; i <= n; ++i) {
        if (s[i] == s[i - 1] || s[i] == s[i - 2])
            ans++, s[i] = '0';
    }

    printf("%d\n", ans);
    return 0;
}