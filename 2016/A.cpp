#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ax, bx, ay, by;
    for (scanf("%d", &n); n--;) {
        scanf("%d%d%d%d", &ax, &ay, &bx, &by);
        printf("%d\n", abs(ax * ay - bx * by));
    }
    return 0;
}