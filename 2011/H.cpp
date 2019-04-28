#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
#define int_max 32760
#define max 100
int imp = 1;
bool visted[max] = {true};
int path[max];
int mi = int_max;
int tim = int_max;


typedef struct {
    int vn, en;

    int cost[max][max];
    int time[max][max];


} G;

void creat(G &g) {

    int i, j;
    for (i = 0; i < g.vn; i++) {
        for (j = 0; j < g.en; j++) {
            g.cost[i][j] = g.time[i][j] = int_max;
        }
    }
    int a, b, p, t;
    for (i = 0; i < g.en; i++) {
        cin >> a >> b >> p >> t;
        g.cost[a][b] = p;
        g.time[a][b] = t;
    }
    visted[0] = true;
    path[1] = 0;
}


void fun(G g, int n) {


    int t = 1;
    int i;
    for (i = 1; i < n; i++) {

        t += g.time[path[i]][path[i + 1]];
    }
    t += g.vn - 1;
    if (t == 6 || t == 7) {
        tim = t;
        int cst = 0;
        for (i = 1; i < n; i++) {
            cst += g.cost[path[i]][path[i + 1]];
        }
        if (mi > cst) {
            mi = cst;
        }
    }

}


int bound(G g, int path[], int p) {
    if (p == 2) {
        return 1;
    }

    if (path[p - 1] == path[p]) {
        return 0;
    }

    if (g.time[path[p - 1]][path[p]] == int_max) {
        return 0;
    }
    return 1;
}

void back(G g, int p) {
    int i;
    if (p > g.vn) {
        if (g.time[path[p - 1]][path[1]] != int_max) {
            path[p] = path[1];
            imp = 0;
            fun(g, p);
        }
    } else {
        for (i = 0; i < g.vn; i++) {

            if (!visted[i]) {
                path[p] = i;
                visted[i] = true;
                if (bound(g, path, p)) {
                    back(g, p + 1);
                }

                visted[i] = false;
            }

        }
    }
}


int main(void) {
    G g;
    int a, b;
    while (scanf("%d %d", &a, &b) == 2) {
        memset(visted, false, sizeof(visted));
        tim = int_max;
        mi = int_max;
        imp = 1;
        g.vn = a;
        g.en = b;
        creat(g);
        back(g, 2);
        if (imp == 1) {
            printf("It's not my thing!\n");
        } else if (tim == 6 || tim == 7) {
            printf("%d\n", mi);
        } else {
            printf("Oh, My god!\n");
        }
    }

    return 0;
}