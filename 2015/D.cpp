#include<iostream>

using namespace std;

int main() {

    int T;
    double a[6][6];
    int i = 0;
    int j = 0;
    int n, m;
    double max;
    cin >> T;
    while (T--) {
        cin >> n;

        for (i = 1; i < 6; i++) {
            for (j = 1; j < 6; j++) {
                cin >> a[i][j];
            }
        }

        cin >> m;
        if (1 == n) {
            cout << m << endl;
            continue;
        }
        max = a[1][m];
        int temp = 1;
        while (n--) {
            for (i = 1; i < 6; i++) {
                if (a[i][m] > max) {
                    max = a[i][m];
                    temp = i;
                }
            }
            m = temp;
        }
        cout << m << endl;
    }
    return 0;
}


