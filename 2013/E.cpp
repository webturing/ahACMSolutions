#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>

using namespace std;
#define MAXN 110
#define eps 1e-10
#define zero(x) (((x)>0?(x):-(x))<eps)

struct pt {
    double x, y;

    pt() {}

    pt(double xx, double yy) {
        x = xx;
        y = yy;
    }
};

double dist(pt p1, pt p2)//点到点的距离
{
    return sqrt(1.0 * (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double Cross(pt a, pt b)//叉乘
{
    return a.x * b.y - a.y * b.x;
}

double Cross(pt a, pt b, pt c)//叉乘
{
    return Cross(pt(a.x - c.x, a.y - c.y), pt(b.x - c.x, b.y - c.y));
}

double same_side(pt p1, pt p2, pt l1, pt l2)//同一面
{
    return Cross(l1, p1, l2) * Cross(l1, p2, l2) > eps;
}


struct Convex {
    int n;
    pt p[MAXN];
};
struct Plane//半平面,a,b构成直线,side表示在哪个面
{
    pt a, b, side;
};

/*
**ret.x-u1.x=t(u2.x-u1.x)
**ret.y-u1.y=t(u2.y-u1.y)
**ret.x-v1.x=tt(v2.x-v1.x)
**ret.y-v1.y=tt(v2.y-v1.y)
**解以上方程可得线段交点ret
*/
pt intersection(pt u1, pt u2, pt v1, pt v2) {
    pt ret = u1;
    double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x))
               / ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x));
    ret.x += (u2.x - u1.x) * t;
    ret.y += (u2.y - u1.y) * t;
    return ret;
}

Convex src, ans;

Convex Half_Plane(Convex c, Plane pl)//半平面交,一条直线切割凸包
{
    int i, j;
    double r1, r2;
    Convex ans, ans1;
    ans.n = 0;
    for (i = 0; i < c.n; i++) {
        if (same_side(c.p[i], pl.side, pl.a, pl.b))
            ans.p[ans.n++] = c.p[i];
        if ((!same_side(c.p[i], c.p[(i + 1) % c.n], pl.a, pl.b)) &&
            (!(zero(Cross(c.p[i], pl.a, pl.b)) && zero(Cross(c.p[(i + 1) % c.n], pl.a, pl.b)))))
            ans.p[ans.n++] = intersection(c.p[i], c.p[(i + 1) % c.n], pl.a, pl.b);
//有点在直线上的话该点会被加入两次
    }
    ans1.n = 0;
    for (i = 0; i < ans.n; i++)
        if (!i || !zero(ans.p[i].x - ans.p[i - 1].x) || !zero(ans.p[i].y - ans.p[i - 1].y))
            ans1.p[ans1.n++] = ans.p[i];//过滤重复点
    if (zero(ans1.p[ans1.n - 1].x - ans1.p[0].x) && zero(ans1.p[ans1.n - 1].y - ans1.p[0].y))
        ans1.n--;
    if (ans1.n < 3)
        ans1.n = 0;
    return ans1;
}

bool judge(double x) {
    Convex ans;
    pt tt, ta, tb;
    ans = src;
    for (int i = 0; i < src.n; i++) {
        tt.x = src.p[i].y - src.p[i + 1].y;
        tt.y = src.p[i + 1].x - src.p[i].x;
        double k = x / sqrt(tt.x * tt.x + tt.y * tt.y);
        tt.x = tt.x * k;
        tt.y = tt.y * k;
        ta.x = src.p[i].x + tt.x;
        ta.y = src.p[i].y + tt.y;
        tb.x = src.p[i + 1].x + tt.x;
        tb.y = src.p[i + 1].y + tt.y;
        Plane pl;
        pl.a = ta;
        pl.b = tb;
        pl.side.x = src.p[i].x + tt.x + tt.x;
        pl.side.y = src.p[i].y + tt.y + tt.y;
        ans = Half_Plane(ans, pl);
        if (ans.n == 0) return false;
    }
    return true;
}

int main(int argc, char **argv) {
    //freopen("tempin.txt","r",stdin);
    //freopen("temp.txt","w+",stdout);
    int n, i, j, tcase;
    double maxl;
    while (scanf("%d", &n) != EOF) {
        src.n = n;
        for (i = 0; i < n; i++)
            scanf("%lf %lf", &src.p[i].x, &src.p[i].y);
        src.p[n] = src.p[0];
        double d, maxd = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if ((d = dist(src.p[i], src.p[j])) > maxd)
                    maxd = d;
        double l, r, mid, k, ansd;
        l = 0;
        r = maxd / 2;
        ansd = 0;
        while (l + eps < r) {
            mid = (l + r) / 2;
            if (judge(mid)) {
                ansd = mid;
                l = mid + eps;
            } else {
                r = mid - eps;
            }
        }
        printf("%.2lf\n", ansd);
    }
    return 0;
}

