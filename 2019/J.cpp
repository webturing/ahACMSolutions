#include <iostream>
#include <stack>
#include <list>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <set>

using namespace std;
//************************************
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
typedef bitset<3005> BIT;
const double eps = 1e-10;

template<typename T>
void read(T &x) {
    int f = 1;
    x = 0;
    char s = getchar();
    while (s < '0' || s > '9') {
        if (s == '-') f = -1;
        s = getchar();
    }
    while (s >= '0' && s <= '9') {
        x = x * 10 + s - '0';
        s = getchar();
    }
    x *= f;
}

template<typename T>
void print(T x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

template<typename T>
void println(T x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
    putchar('\n');
}

template<typename T, typename ... Args>
void read(T &x, Args &... args) {
    read(x);
    read(args ...);
}

inline void reads(char *a) { scanf("%s", a); }

template<typename ... Args>
void reads(char *a, Args *... args) {
    scanf("%s", a);
    reads(args...);
}

template<typename T, typename ... Args>
void print(T x, Args ... args) {
    print(x);
    putchar(' ');
    print(args...);
}

template<typename T, typename ... Args>
void println(T x, Args ... args) {
    print(x);
    putchar(' ');
    println(args...);
}

inline void prints(char *a) { printf("%s", a); }

template<typename T>
inline T sqr(T x) { return x * x; }

template<typename T>
inline T random(T R) { return (double) rand() / RAND_MAX * R + ((T) 0.5 == 0 ? 0.5 : 0.0); }

template<typename T>
inline T random(T L, T R) { return random(R - L) + L; }

ll sumi(ll n) { return (1LL + n) * n / 2; }

ll sumi2(ll n) { return (n + 1) * n * (n * 2 + 1) / 6; }

ll ksm(ll a, ll k, ll Mod) {
    ll res = 1;
    while (k) {
        if (k & 1) (res *= a) %= Mod;
        (a *= a) %= Mod;
        k >>= 1;
    }
    return res % Mod;
}

inline ll inv(ll a, ll Mod) { return ksm(a, Mod - 2, Mod); }

inline void cap_bit(ll x) {
    for (int i = 63; i >= 0; --i)
        if (x >> i & 1) {
            printf("Need (%d) = %lld\n", i + 1, 1LL << (i + 1));
            return;
        }
}

inline void cal_space(ll x) { printf("%lld MB\n", x >> 20); }

const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nbsp putchar(' ')
#define br puts("")
#define pi acos(-1.0)
#define gcd(x, y) __gcd(x, y)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define xx first
#define yy second
#define lowbit(x) (x) & (-x)
#define mem(x) memset(x, 0, sizeof x)
const int N = 1e6 + 5;
const int M = 35;
ll Mod = 1e9 + 7;
const ll INF = 1e16;

//ll INV2 = inv(2, Mod);
template<typename T>
inline void addmod(T &a, T b) {
    a += b;
    if (a >= Mod) a -= Mod;
}

template<typename T>
inline void submod(T &a, T b) {
    a -= b;
    if (a < 0) a += Mod;
}
//************************************
namespace int64 {
    typedef long long ll;

    inline ll mul(ll a, ll b, ll Mod) {
        ll res = (ll) a * b - (ll) ((long double) a * b / Mod) * Mod;
        return res < 0 ? res + Mod : (res > Mod ? res - Mod : res);
    }

    ll ksm(ll a, ll b, ll Mod) {
        ll res = 1;
        while (b) {
            if (b & 1) res = mul(res, a, Mod);
            a = mul(a, a, Mod);
            b >>= 1;
        }
        return res;
    }
}
struct Matrix {
    typedef long long Data;
    const static int N = 55;
    Data m[N][N];
    int n;

    Matrix(int _n = N) {
        n = _n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                m[i][j] = 0;
    }

    void unit() {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i == j) m[i][j] = 1;
                else m[i][j] = 0;
    }

    Data *operator[](int r) { return m[r]; }

    Matrix operator*(const Matrix &a) {
        Matrix res(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k) {
                    res.m[i][j] += int64::mul(m[i][k], a.m[k][j], Mod);
                    if (res.m[i][j] >= Mod) res.m[i][j] -= Mod;
                }
        return res;
    }

    Matrix operator^(long long k) {
        Matrix a(*this);
        Matrix res(n);
        res.unit();
        while (k) {
            if (k & 1) res = res * a;
            a = a * a;
            k >>= 1;
        }
        return res;
    }
};
namespace KMP {
    const int N = 1e6 + 5; //模式串长度
    const int M = 26;
    typedef char Data; // 串类型
    Data *P;
    int np;
    int fail[N];
    int ch[N][M];

    //下标从 1 开始
    void init(Data *_P, int _np) {
        np = _np;
        P = _P - 1;
    }

    void kmp() {
        fail[1] = 0;
        int j = 0;
        for (int i = 2; i <= np; ++i) {
            while (j && P[j + 1] != P[i]) j = fail[j];
            if (P[j + 1] == P[i]) j++;
            fail[i] = j;
        }
    }

    void build() {
        for (int i = 0; i <= np; ++i) {
            for (int j = 0; j < M; ++j) {
                int cur = i;
                while (cur > 0 && (cur == np || P[cur + 1] != 'a' + j)) cur = fail[cur];
                if (P[cur + 1] == 'a' + j) cur++;
                ch[i][j] = cur;
            }
        }
    }
}
ll T, n;
char s[N];

int main() {
    IOS;
    cin >> T;
    while (T--) {
        cin >> n >> Mod;
        cin >> s;
        int len = strlen(s);
        KMP::init(s, len);
        KMP::kmp();
        KMP::build();
        Matrix ma(len + 1);
        for (int u = 0; u < len; ++u) {
            for (int j = 0; j < 26; ++j) {
                int v = KMP::ch[u][j];
                if (v == len) continue;
                ma[u][v]++;
            }
        }
        ma = ma ^ n;
        ll ans = int64::ksm(26, n, Mod);
        for (int i = 0; i < len; ++i) ans -= ma[0][i];
        ans %= Mod;
        ans += Mod;
        ans %= Mod;
        cout << ans << endl;
    }
    return 0;
}