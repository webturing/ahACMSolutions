#include <iostream>

using namespace std;

int main() {
    for (int n, m; cin >> n >> m;) {
        for (int i = 0; i <= n; i++) {
            int j = n - i;
            if (4 * i + 2 * j == m) {
                cout << i << " " << j << endl;
                break;
            }
        }
    }
    return 0;
}