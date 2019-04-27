//
// Created by jal on 2019-04-27.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

//Lucas定理实现C(n,m)%p的代码：
LL exp_mod(LL a, LL b, LL p)
{ //快速幂取模
    LL res = 1;
    while(b != 0)
    {
        if(b&1) res = (res * a) % p;
        a = (a*a) % p;
        b >>= 1;
    }
    return res;
}

LL Comb(LL a, LL b, LL p)
{ //求组合数C(a,b)%p
    if(a < b)   return 0;
    if(a == b)  return 1;
    if(b > a - b)   b = a - b;

    LL ans = 1, ca = 1, cb = 1;
    for(LL i = 0; i < b; ++i)
    {
        ca = (ca * (a - i))%p;
        cb = (cb * (b - i))%p;
    }
    ans = (ca*exp_mod(cb, p - 2, p)) % p;
    return ans;
}

LL Lucas(LL n,LL m,LL p)
{ //Lucas定理求C(n,m)%p
    LL ans = 1;

    while(n&&m&&ans)
    {
        ans = (ans*Comb(n%p, m%p, p)) % p;
        n /= p;
        m /= p;
    }
    return ans;
}
const int MOD = 10007;
int main(){
    int n;
    ifstream cin("e.in");
    ofstream cout("e.out");
    while (cin >> n){
        if(n==1){
            cout << 1 << endl;
            continue;
        }
        if(n % 2 == 0){
            cout << 0 << endl;
            continue;
        }
        n = (n-1)/2;
        cout << (Lucas(2*n, n, MOD) -  Lucas(2*n, n-1, MOD) + MOD)%MOD<< endl;
    }
}