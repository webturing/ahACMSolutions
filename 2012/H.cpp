#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    //clock_t t1 = clock();
    //freopen( "a.in", "r", stdin );
    //freopen( "a.out", "w", stdout );
    int x, d, l, h, a, b, cas = 0, t, r;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &l, &h, &a, &b);
        r = -1;
        if ((a % b) == 0 && a >= l && a <= h) r = a;
        for (x = 1; x * x <= a && x <= h; ++x) {
            if (a % x) continue;
            if ((x % b) == 0) {
                if (x >= l && x <= h) {
                    r = x;
                    break;
                }
            }
            d = a / x;
            if ((d % b) == 0) {
                if (d >= l && d <= h) r = d;
            }
        }
        printf("Case #%d: %d\n", ++cas, r);
    }
    //clock_t t2 = clock();
    //printf( "%.3f ms\n", ( t2 - t1 ) * 1.0 / CLOCKS_PER_SEC * 1000.0 );
    return 0;
}