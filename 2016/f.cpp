#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 10000;
vector<int> G[MAXN + 5];
int indeg[MAXN + 5];

int main() {
  int T, n, m;
  for (scanf("%d", &T); T--;) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      G[i].clear();
      indeg[i] = 0;
    }
    vector<int> ans;
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      G[a].push_back(b);
      indeg[b]++;
    }
    priority_queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (!indeg[i]) q.push(i);
    }
    while (!q.empty()) {
      int x = q.top();
      q.pop();
      ans.push_back(x);
      for (int i = 0; i < G[x].size(); i++) {
        int y = G[x][i];
        indeg[y]--;
        if (!indeg[y]) q.push(y);
      }
    }
    if (ans.size() != n) {
      puts("-1");
      continue;
    }
    for (int i = 0; i < n; i++) {
      printf(i == n - 1 ? "%d\n" : "%d ", ans[i]);
    }
  }
  return 0;
}
