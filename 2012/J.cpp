#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <sys/timeb.h>

const double rate = 0.99;
const double rad = 1000.0;
const double eps = 0.01;
const double nts = 30;
const double pi2 = 2.0 * acos(-1.0);
struct point {
    double x, y, z;
};

inline double dis(const point &a, const point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

double buf[4];

double cal_dif(point p[], const point &tp) {
    int i;
    double sum = 0, x;
    for (i = 0; i < 4; ++i) {
        buf[i] = dis(tp, p[i]);
        sum += buf[i];
    }
    x = sum / 4.0;
    double re = 0;
    for (i = 0; i < 4; ++i) {
        re += (buf[i] - x) * (buf[i] - x);
    }
    return re;
}

int main(int argc, char *argv[]) {
    //timeb t1;
    //ftime( &t1 );
    //freopen( "c.out", "w", stdout );
    //freopen( "c.in", "r", stdin );
    srand(unsigned(time(NULL)));
    point p[4], o, to;
    double d, dif, td;
    int t, i, cas = 0;
    scanf("%d", &t);
    while (t--) {
        for (i = 0; i < 4; ++i) {
            scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
        }
        o.x = 0;
        o.y = 0;
        o.z = 0;
        for (i = 0; i < 4; ++i) {
            o.x += p[i].x;
            o.y += p[i].y;
            o.z += p[i].z;
        }
        o.x /= 4.0;
        o.y /= 4.0;
        o.z /= 4.0;
        dif = cal_dif(p, o);
        d = rad;
        double a1, a2;
        while (d > eps) {
            for (i = 0; i < nts; ++i) {
                a1 = (double) (rand()) * pi2 / 32767.0;
                a2 = (double) (rand()) * pi2 / 32767.0;
                to.x = o.x + d * cos(a2) * cos(a1);
                to.y = o.y + d * cos(a2) * sin(a1);
                to.z = o.z + d * sin(a2);
                if (fabs(to.x) > 500 || fabs(to.y) > 500 ||
                    fabs(to.z) > 500)
                    continue;
                td = cal_dif(p, to);
                if (td < dif) {
                    dif = td;
                    o = to;
                }
            }
            d *= rate;
        }
        if (fabs(o.x) < 0.01) o.x = fabs(o.x);
        if (fabs(o.y) < 0.01) o.y = fabs(o.y);
        if (fabs(o.z) < 0.01) o.z = fabs(o.z);
        printf("Case #%d: ", ++cas);
        printf("%.1f %.1f %.1f\n", o.x, o.y, o.z);
    }
    //timeb t2;
    //ftime( &t2 );
    //printf( "%d ms\n", t2.millitm - t1.millitm + 1000 * ( t2.time - t1.time ) );
    return 0;
}