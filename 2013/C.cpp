#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1010;

struct Proc {
    int a, e;
} p[maxn];
int n;

bool cmp(Proc p1, Proc p2) {
    if (p1.a != p2.a) {
        return p1.a < p2.a;
    }
    return p1.e < p2.e;
}

int main() {
    //freopen("W.进程调度.in", "r", stdin);
    //freopen("W.进程调度.out", "w", stdout);
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &p[i].a, &p[i].e);
        }
        sort(p, p + n, cmp);
        int waitTime = 0;
        int exeTime = 0;
        int endTime = p[0].a;
        for (int i = 0; i < n; ++i) {
            if (p[i].a < endTime) {
                waitTime += (endTime - p[i].a);
                exeTime += p[i].e;
                endTime += p[i].e;
            } else {
                exeTime += p[i].e;
                endTime = p[i].a + p[i].e;
            }
        }
        printf("%.4lf\n", (exeTime + waitTime) / (1.0 * n));
    }
    return 0;
}
