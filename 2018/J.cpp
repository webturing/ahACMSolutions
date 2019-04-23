#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    LL n;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 4 == 0) {
            cout << "Bob win" << endl;
        } else {
            cout << "Alice win" << endl;
        }
    }

    return 0;
}