#include<iostream>

using namespace std;
#define LL long long

LL yue(LL a, LL b)   //最小公约数
{
    if (b == 0) {
        return a;
    }
    int c = (a > b ? b : a);
    int n;
    for (n = 1; n <= c; n++) {
        if (a % n == 0 && b % n == 0) {
            return n;
        } else {
            continue;
        }
    }
}

LL bei(LL a, LL b)  //最大公倍数
{
    return a * b / yue(a, b);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        LL n;
        LL a;
        cin >> n;
        if (n == 1) {
            cout << 1 << endl;
        }
        if (n == 2) {
            cout << 2 << endl;
        }
        if (n % 2 != 0) {
            cout << n * (n - 1) * (n - 2) << endl;
        }
        if (n % 2 == 0) {
            if (yue(n, n - 3) == 1 && yue(n - 1, n - 3) == 1) {
                a = bei(n, bei(n - 1, n - 3));
            } else {
                a = bei(n - 1, bei(n - 2, n - 3));
            }
            cout << a << endl;
        }
    }
    return 0;
}

