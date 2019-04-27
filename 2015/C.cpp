#include<iostream>

using namespace std;

int main() {
    int a[1000];
    int b[1000];
    int c[1000];
    int d[1000];
    int i = 0;
    int j = 0;
    int T;

    cin >> T;
    while (T--) {
        int n;
        int num1;
        int num2;
        cin >> n;

        for (i = 0; i < n; i++) {
            cin >> num1 >> num2;
            a[i] = num1;
            b[i] = num2;
        }

        int t = 0;
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (a[i] == a[j])
                    continue;
                c[t] = (b[j] - b[i]) / (a[j] - a[i]);
                t++;
            }
        }

        int num = 0;
        int k = 0;
        while (t--) {
            for (i = 0; i < num; i++) {
                if (d[i] == c[t])
                    break;
            }
            if (i == num)
                num++;
            d[num] = c[t];
        }
        cout << num << endl;
    }
    return 0;
}



