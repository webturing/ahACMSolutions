#include <iostream>

using namespace std;

int main() {
    int T, n, m, p, q, i = 0, x, y, z, h[100][100], a, b, th[100];
    cin >> T;
    while (T > i) {
        cin >> n >> m >> p >> q;
        x = 0, y = 0;
        while (x < n) {
            while (y < m) {
                cin >> h[x][y];
                y++;
            }
            y = 0;
            x++;
        }
        x = 0, y = 0, z = 1, b = 0;
        while (b < p) {
            while (b < p) {
                x = 0, y = 0;
                while (x < n) {
                    while (y < m) {
                        if (h[x][y] <= z) {
                            if (x >= 1) {
                                if (h[x - 1][y] == 0) a = 1;
                            } else a = 1;
                            if (y >= 1) {
                                if (h[x][y - 1] == 0) a = 1;
                            } else a = 1;
                            if (x < n - 1) {
                                if (h[x + 1][y] == 0) a = 1;
                            } else a = 1;
                            if (y < m - 1) {
                                if (h[x][y + 1] == 0) a = 1;
                            } else a = 1;
                        }
                        if (a == 1) h[x][y] = 0;
                        a = 0;
                        y++;
                    }
                    y = 0;
                    x++;
                }
                z++;
                x = 0, y = 0, b = 0;
                while (n > x) {
                    while (m > y) {
                        if (h[x][y] == 0)b++;
                        y++;
                    }
                    y = 0;
                    x++;
                }
                if (b > q) th[i] = -1;
                else th[i] = z - 1;
            }
        }
        i++;
    }
    i = 0;
    while (T > i) {
        cout << th[i] << endl;
        i++;
    }
    return 0;
}
