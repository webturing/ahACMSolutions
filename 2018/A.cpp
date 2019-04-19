#include<bits/stdc++.h>

using namespace std;

inline int f(int n) {
    int tot = 0;
    while (n % 7 == 0) {
        ++tot;
        n /= 7;
    }
    return tot;
}

inline int g(int n) {
    int tot = 0;
    while (n > 0) {
        if (n % 10 == 7)++tot;
        n /= 10;
    }
    return tot;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int L, R;
        cin >> L >> R;
        int tot = 0;
        for (int n = L; n <= R; n++) {
            tot += f(n) + g(n);
        }
        cout << tot << endl;
    }
    return 0;
}
