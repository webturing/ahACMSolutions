#include<iostream>

using namespace std;

int main() {
    int n, cm, ca;
    while (cin >> n >> cm >> ca) {
        if (n == 0)
            cout << 0 << endl;
        else if (n > 2 * cm) {
            if (ca > cm)
                cout << -1 << endl;
            else if (ca == cm)
                cout << 0 << endl;
            else
                cout << 1 << endl;
        } else {
            int winner = n / 2 + 1;
            int draw = n / 2;
            if (n % 2 == 1) {
                if (ca >= (cm / winner + 1) * winner)
                    cout << -1 << endl;
                else
                    cout << 1 << endl;
            } else {
                if (ca >= (cm / draw + 1) * winner)//Òþº¬cmÖÁÉÙÄÜÄÃµ½Æ½¾Ö
                    cout << -1 << endl;
                else if (ca < (cm / winner + 1) * draw)
                    cout << 1 << endl;
                else
                    cout << 0 << endl;
            }
        }
    }
}
