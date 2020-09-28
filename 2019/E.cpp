#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn = 1005;
struct Point {
    double x, y;
} p[maxn];
set<float> q; //保存整体对称轴的斜率,set的size就是整体对称轴的条数
double cross(Point a, Point b, Point c) {//叉积
    return ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}

double dis(Point a, Point b) {//两点距离
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmp(Point a, Point b) {
    if (cross(p[0], a, b) == 0)
        return dis(a, p[0]) < dis(b, p[0]);
    else
        return cross(p[0], a, b) > 0;
}

double k(Point a, Point b) {//斜率
    if (a.x == b.x)
        return double(1e9);
    else if (a.y == b.y)
        return 0;
    else
        return (b.y - a.y) / (b.x - a.x);
}

int main() {
    int n;
    cin >> n;
    Point ave; //平均值点
    ave.x = 0;
    ave.y = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        ave.x += p[i].x;
        ave.y += p[i].y;
    }
    ave.x /= n;
    ave.y /= n;
    //开始求凸包
    for (int i = 1; i < n; ++i) {
        if ((p[i].y < p[0].y)) {
            swap(p[0], p[i]);
        } else if (p[i].y == p[0].y && p[i].x < p[0].x) {
            swap(p[i], p[0]);
        }
    }
    sort(p + 1, p + n, cmp);
    int tot = 1;
    for (int i = 2; i < n; ++i) { //手写栈
        while (tot > 0 && cross(p[tot - 1], p[tot], p[i]) <= 0) {
            tot--;
        }
        tot++;
        p[tot] = p[i];
    }
    Point temp; //凸包线段上的中点
    bool flag = 0;
    int ans = 0;
    q.clear();
    for (int i = 0; i <= tot; ++i) {
        for (int j = i + 1; j <= tot; ++j) {
            temp.x = (p[i].x + p[j].x) / 2;
            temp.y = (p[i].y + p[j].y) / 2;
            flag = 0;
            if (float(temp.x - ave.x) * (p[i].x - p[j].x) + float(temp.y - ave.y) * (p[i].y - p[j].y) ==
                0) { //经过平均值点的凸包上的中垂线即为整体对称轴
                flag = 1;
            }
            if (flag) {
                if (temp.x == ave.x && temp.y == ave.y) {
                    q.insert(k(p[i], p[j]));
                } else {
                    q.insert(k(temp, ave));
                }
            }
        }
    }
    ans = q.size();
    if (tot == 1) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}