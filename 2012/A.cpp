#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
#define MM(arr, ele) memset(arr,ele,sizeof(arr))
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define FFF(i, a) for(int i=0;i<a;i++)
#define FFD(i, a, b) for(int i=a;i>=b;i--)
#define LL long long
#define i64 __int64
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define SC(a) scanf("%d",&a)

int s[10000010];

int main() {
    int n;
    while (~SC(n)) {
        int x, p = 1;
        int ans = 0;
        SC(s[1]);
        s[0] = -1;
        FFF(i, n - 1) {
            SC(x);
            if (x < s[p]) {
                while (x < s[p] && p > 0) {
                    ans += max(s[p - 1], x);
                    p--;
                }
                s[++p] = x;
            } else s[++p] = x;
        }
        FFD(i, p - 1, 1) ans += s[i];
        cout << ans << endl;
    }
    return 0;
}
