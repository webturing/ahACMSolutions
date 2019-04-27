#include<iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        int k;
        cin >> n >> k;
        int num = 1;
        int num1 = 1;
        int sum = 0;
        int a = -1;
        while (num <= n) {
            sum = sum + a * num;
            if (num1 == k) {
                a = a * (-1);
                num1 = 0;
            }
            num1++;
            num++;
        }
        cout << sum << endl;
    }
    return 0;
}


