#include<iostream>

using namespace std;
#ifdef _WIN32
#define i64 __int64
#else
#define i64 long long
#endif

i64 find(i64 x, i64 y) {
    if (x == 0 || y == 0) return 0;
    if (x < y) swap(x, y);
    return x / y + find(x % y, y);
}

int main() {
    i64 a, b, c;
    while (cin >> a >> b >> c) {
        if (a == 0 && b == 0 && c == 0) return 0;
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);
        cout << find(a, b) << endl;
    }
    return 0;
}

