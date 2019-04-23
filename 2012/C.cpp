#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

using namespace std;

typedef double DB;
typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<PII> VPII;

#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(), (x).end()
#define CLR(a, x) memset(a, x, sizeof(a))

template<class T>
inline void checkMin(T &a, T b) {
    if (b < a) a = b;
}

template<class T>
inline void checkMax(T &a, T b) {
    if (b > a) a = b;
}

const int N = 102;
const int M = 20002;

bool dp[N * M];
int n, A[N], B[N];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("stone.out", "w", stdout);

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &B[i]);
        }

        int As = 0, Bs = 0;
        for (int i = 0; i < n; i++) As += A[i], Bs += B[i];

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        VI x;
        x.push_back(0);
        for (int i = 0; i < n; i++) {
            int w = A[i] + B[i];
            int t = x.size();
            for (int j = 0; j < t; j++) {
                int k = w + x[j];
                if (k <= As + Bs && !dp[k]) dp[k] = true, x.push_back(k);
            }
        }

        int ans = (Bs - As + 1) / 2;
        bool flag = false;
        for (int i = Bs - ans; i <= ans + As; i++) flag |= dp[i];
        while (!flag) {
            ans++;
            flag |= dp[Bs - ans];
            flag |= dp[ans + As];
        }

        printf("%d\n", ans);
    }
    return 0;
}
