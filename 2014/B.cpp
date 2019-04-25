#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    int n, k, t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int sum = 0;
        int flag = -1;
        for (int i = 1; i <= n; i++) {
            int j;
            for (j = i; j <= i + k - 1; j++)
                sum += flag * j;
            flag = 0 - flag;
            i = j - 1;
        }
        cout << sum << endl;
    }
    return 0;
}