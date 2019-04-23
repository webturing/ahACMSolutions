#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

#define EPS 1e-6
#define PI acos(-1.0)
using namespace std;
struct point {
    double x, y, r;
} start, line[2], cir;

double cross(const point &p1, const point &p2, const point &q1, const point &q2)//叉乘
{
    return (q2.y - q1.y) * (p2.x - p1.x) - (q2.x - q1.x) * (p2.y - p1.y);
}

double dis(const point &p, const point &q)//点与点的距离
{
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

point rorate(const point &p, const double &angle)//按弧度枚举圆上的点
{
    point ans, temp;
    ans.x = p.x + p.r * cos(angle);
    ans.y = p.y + p.r * sin(angle);
    return ans;
}

double dot(const point &p1, const point &p2, const point &q1, const point &q2)//点积
{
    return (p2.x - p1.x) * (q2.x - q1.x) + (p2.y - p1.y) * (q2.y - q1.y);
}


double dis_line(const point &p)//点到线段
{
    if (dot(line[0], line[1], line[0], p) * dot(line[1], line[0], line[1], p) > 0) {
        return fabs(cross(line[0], line[1], line[0], p)) / dis(line[0], line[1]);
    } else {
        return min(dis(line[0], p), dis(line[1], p));
    }
    return 0;
}

double thr_search(double angle, double st)//主要的部分，三分的程序
{
    point temp1, temp2;
    double l(st), r(angle), mid1, mid2;
    while (fabs(r - l) > EPS) {
        mid1 = (r + l) / 2;
        mid2 = (mid1 + r) / 2;
        temp1 = rorate(cir, mid1);
        temp2 = rorate(cir, mid2);
        if (dis_line(temp1) + dis(temp1, start) <= dis_line(temp2) + dis(temp2, start))r = mid2;
        else l = mid1;
    }
    temp1 = rorate(cir, l);
    return dis_line(temp1) + dis(temp1, start);
}

int main() {
    //freopen("tempin.txt","r",stdin);
    //freopen("temp.txt","w+",stdout);
    int cnt = 0;
    while (scanf("%lf%lf", &start.x, &start.y) != EOF) {
        scanf("%lf%lf%lf", &cir.x, &cir.y, &cir.r);
        for (int i(0); i < 2; i++)scanf("%lf%lf", &line[i].x, &line[i].y);
        double angle = PI, st = 0;//先对[0,pi]进行三分
        double ans = thr_search(angle, st);
        angle += PI;
        st += PI;//再对[pi,2pi]进行三分
        ans = min(ans, thr_search(angle, st));
        printf("%.2lf\n", ans);
    }
    return 0;
}
