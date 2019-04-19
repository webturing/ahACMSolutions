#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

template <class T>
inline void scan(T &ret) {
  char c;
  ret = 0;
  while ((c = getchar()) < '0' || c > '9')
    ;
  while (c >= '0' && c <= '9') ret = ret * 10 + (c - '0'), c = getchar();
}

inline void out(int x) {
  if (x > 9) out(x / 10);
  putchar(x % 10 + '0');
}

struct Flag {
  int p, t;  //-1 or +1
  Flag() {}
  Flag(int a, int b) : p(a), t(b) {}
  bool operator<(const Flag &b) const {
    if (p != b.p) return p < b.p;
    return t > b.t;
  }
} flag[20005];

int start[40005];
int rcnt;

int main() {
  int T, n, q;
  for (scan(T); T--;) {
    scan(n);
    scan(q);
    for (int i = 0; i < n; i++) {
      int l, r;
      scan(l);
      scan(r);
      ++l;
      ++r;
      l = l * 2 - 1;
      r = r * 2 - 1;
      flag[i * 2] = Flag(l, 1);
      flag[i * 2 + 1] = Flag(r + 1, -1);
    }
    sort(flag, flag + 2 * n);

    rcnt = 0;
    start[rcnt++] = flag[0].p;
    int gcnt = 0;
    for (int i = 0; i < 2 * n; i++) {
      gcnt += flag[i].t;
      if (gcnt == 0) {
        start[rcnt++] = flag[i].p;
        start[rcnt++] = flag[i + 1].p;
      }
    }
    start[rcnt - 1] = INT_MAX;

    for (; q--;) {
      int l, r;
      scan(l);
      scan(r);
      ++l;
      ++r;
      l = l * 2 - 1;
      r = r * 2 - 1;
      int al = upper_bound(start, start + rcnt, l) - start;
      int ar = lower_bound(start, start + rcnt, r) - start;
      if (start[al] == l) ++al;
      if (start[ar] == r) ++ar;
      int ans = (ar >> 1) - (al >> 1);
      if ((al & 1) == 0) ++ans;
      out(ans);
      puts("");
    }
    if (T != 0) puts("");
  }
  return 0;
}
