#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int person[1005];
int f[1005][1005];
const int inf = INT_MAX / 2;

int main() {
  int T, n, p, c;
  for (scanf("%d", &T); T--;) {
    scanf("%d%d%d", &p, &n, &c);
    for (int i = 0; i < p; i++) scanf("%d", &person[i]);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j)
          f[i][j] = 0;
        else
          f[i][j] = inf;
      }
    }
    for (; c--;) {
      int x, y, v;
      scanf("%d%d%d", &x, &y, &v);
      f[x][y] = min(f[x][y], v);
      f[y][x] = f[x][y];
    }

    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        }
      }
    }

    int minans = INT_MAX;
    for (int i = 1; i <= n; i++) {
      int tans = 0;
      for (int j = 0; j < p; j++) tans += f[i][person[j]];
      minans = min(minans, tans);
    }
    printf("%d\n", minans);
  }
  return 0;
}
