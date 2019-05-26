//
// Created by jal on 2019-05-26.
//

#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    int a[8] = {2, 5, 7, 10, 13, 14, 17, 18};
    while (t--) {
        int n, m;
        cin >> n >> m;
        set<int> S;
        int x;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            for (int j = 0; j <= 7; j++) {
                int y = x ^(1 << (a[j] - 1));
                S.insert(y);
            }
        }
        for (int i = 1; i <= m; i++) {
            cin >> x;
            int flag = 1;
            for (int j = 0; j <= 7; j++) {
                int y = x ^(1 << (a[j] - 1));
                if (S.find(y) == S.end()) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                cout << "yes" << " ";
            } else {
                cout << "no" << " ";
            }
        }
    }
}
