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

const int MAXN = 52;

int N, M, K;
LL dp[MAXN][MAXN][MAXN * MAXN];

LL inv(LL a) {
    return a == 1 ? 1 : (M - M / a) * inv(M % a) % M;
}

LL mPow(LL x, int n) {
    LL ret = 1;
    while (n) {
        if (n & 1) ret = ret * x % M;
        x = x * x % M;
        n >>= 1;
    }
    return ret;
}

LL mC(int n, int m) {
    LL ret = 1;
    for (int i = 1; i <= m; i++, n--) {
        ret = ret * n % M * inv(i) % M;
    }
    return ret;
}

inline void add(LL &a, LL b) {
    a += b;
    if (a >= M) a -= M;
}

int main() {
    freopen("1.in", "r", stdin);
    freopen("luck.out", "w", stdout);

    while (cin >> N >> K >> M) {

        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= N; i++) {
            dp[i][0][0] = 1;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= K && j <= i; j++) {
                int w1 = (j + 1) * j / 2;
                int w2 = (i + i - j + 1) * j / 2;
                for (int k = w1; k <= w2; k++) {
                    add(dp[i][j][k], dp[i - 1][j - 1][k - i]);
                    add(dp[i][j][k], dp[i - 1][j][k]);
                }
            }
        }

        LL total = mPow(mC(N, K), 2), cnt = 0;
        int w1 = (1 + K) * K / 2;
        int w2 = (N + N - K + 1) * K / 2;
        for (int i = w1; i <= w2; i++) {
            add(cnt, dp[N][K][i] * dp[N][K][i] % M);
        }

        LL ans = (total - cnt + M) % M * inv(2) % M;
        cout << ans << endl;
    }
    return 0;
}
