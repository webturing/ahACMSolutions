#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Point {
  double x, y;
  Point(double px = 0.0, double py = 0.0) : x(px), y(py) {}
  bool operator==(const Point &b) const {
    return fabs(x - b.x) < 1e-9 && fabs(y - b.y) < 1e-9;
  }
  Point operator-(Point b) { return Point(x - b.x, y - b.y); }
  Point operator+(Point b) { return Point(x + b.x, y + b.y); }
  Point operator*(double k) { return Point(x * k, y * k); }
} point[205];

int n;
Point ob;

double dis(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

bool cmp(Point a, Point b) { return cross(a - ob, b - ob) > 1e-9; }

struct Line {
  Point a, b;
  Point p, v;
  Line() {}
  Line(Point pa, Point pb) : a(pa), b(pb) {
    p = a;
    v = b - a;
  }
  bool hasCommonPoint(const Line &lb) {
    return a == lb.a || a == lb.b || b == lb.a || b == lb.b;
  }
  double distanceToPoint(Point p) {
    if (a == b) return dis(p, a);
    Point v1 = b - a, v2 = p - a, v3 = p - b;
    if (v1.x * v2.x + v1.y * v2.y < -1e-9)
      return sqrt(v2.x * v2.x + v2.y * v2.y);
    else if (v1.x * v3.x + v1.y * v3.y > 1e-9)
      return sqrt(v3.x * v3.x + v3.y * v3.y);
    else
      return fabs(cross(v1, v2)) / sqrt(v1.x * v1.x + v1.y * v1.y);
  }
  Point getCrossPoint(Line lb) {
    Point u = a - lb.a;
    Point v = b - a;
    Point w = lb.b - lb.a;
    double t = cross(w, u) / cross(v, w);
    return a + v * t;
  }
  Point point(double x) { return p + v * x; }
};

struct Circle {
  Point c;
  double r;
  Circle(Point c, double r) : c(c), r(r) {}
  Point point(double a) { return Point(c.x + cos(a) * r, c.y + sin(a) * r); }
};

int getLineCircleIntersection(Line L, Circle C, double &t1, double &t2,
                              vector<Point> &sol) {
  double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
  double e = a * a + c * c, f = 2 * (a * b + c * d),
         g = b * b + d * d - C.r * C.r;
  double delta = f * f - 4 * e * g;
  if (delta < -1e-9) return 0;
  if (fabs(delta) < 1e-9) {
    t1 = t2 = -f / (2 * e);
    sol.push_back(L.point(t1));
    return 1;
  }
  t1 = (-f - sqrt(delta)) / (2 * e);
  sol.push_back(L.point(t1));
  t2 = (-f + sqrt(delta)) / (2 * e);
  sol.push_back(L.point(t2));
  return 2;
}

int main() {
  int T;
  for (scanf("%d", &T); T--;) {
    double a, b, r, x, y, w, t;
    scanf("%lf%lf%lf%lf%lf%lf%lf", &a, &b, &r, &x, &y, &w, &t);
    Circle cir = Circle(Point(a, b), r);
    Point pa = cir.point(w * t);
    Point pb = Point(x, y);
    Line l = Line(pa, pb);
    double t1, t2;
    vector<Point> ans;
    int ret = getLineCircleIntersection(l, cir, t1, t2, ans);
    if (ret == 1) {
      puts("0.00");
    } else {
      printf("%.2f\n", dis(ans[0], ans[1]));
    }
  }
  return 0;
}
