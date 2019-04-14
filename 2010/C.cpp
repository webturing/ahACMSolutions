#include<bits/stdc++.h>

using namespace std;
typedef long long LL;


const int N = 1000000 + 10;
const int MOD = 10007L;
LL h[N] = {1, 2};

void init(int m) {
    //h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)h(0)
    for (int n = 0; n < m; n++) {
        if (h[n])continue;
        for (int j = 0; j <= n - 1; j++) {
            h[n] = (h[n] + (h[j] * h[n - j])) % MOD;
        }
    }
}

int main() {

    int n;
    while (cin >> n) {
        init(n);
        if (n & 1) {
            n >>= 1;
            cout << h[n / 2] << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}