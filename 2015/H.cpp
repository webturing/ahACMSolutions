include <iostream>
using namespace std;

bool is_flame(int num) {
    int i = 0;

    for (i = 2; i < num; i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}

int main() {
    int T;
    int direaction = 1;
    int n, m;
    int a, b;

    cin >> T;
    while (T--) {
        cin >> n >> m;
        cin >> a >> b;

        if (m == a) {
            cout << b << endl;
            continue;
        }

        while (m != a) {
            if (direaction) {
                if (a == n) {
                    a = 1;
                    b++;
                    if (is_flame(b)) {
                        direaction = 0;
                    }
                } else {
                    a++;
                    b++;
                    if (is_flame(b)) {
                        direaction = 0;
                    }
                }
            } else {
                if (a == 1) {
                    a = n;
                    b++;
                    if (is_flame(b)) {
                        direaction = 1;
                    }
                } else {
                    a--;
                    b++;
                    if (is_flame(b)) {
                        direaction = 1;
                    }
                }
            }
        }
        if (is_flame(b)) {
            cout << "duang" << endl;
        } else {
            cout << b << endl;
        }
    }
    return 0;
}
