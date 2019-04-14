#include<iostream>
#include<stdio.h>

using namespace std;

int main() {
    int n, T;
    while (cin >> n >> T) {
        int left = 1, right = n;
        int ans = 0;
        while (left != right) {
            int mid = (left + right) / 2;
            int a = mid - left;
            int b = right - mid;
            if (a >= b) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            ans++;
        }
        if (ans <= T)
            cout << ans << endl;
        else
            cout << "Impossible" << endl;
    }
    return 0;
}