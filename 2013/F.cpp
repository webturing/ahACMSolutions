#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
vector<char> tab[10];

void ini() {
    tab[0].push_back(' ');
    tab[1].push_back(',');
    tab[1].push_back('.');
    tab[1].push_back('!');
    char temp = 'a';
    for (int i(2), j(0); i < 10; ++i) {
        tab[i].push_back(temp + j++);
        tab[i].push_back(temp + j++);
        tab[i].push_back(temp + j++);
        if (i == 7 || i == 9)tab[i].push_back(temp + j++);
    }
}

int get_kind(char a) {
    if (a <= 'z' && a >= 'a')return 0;
    if (a == ' ' || a == ',' || a == '.' || a == '!')return 0;
    if (a <= 'Z' && a >= 'A')return 1;
    if (a <= '9' && a >= '0')return 2;
}

int get_key(char a, int &pos) {
    if (a >= 'A' && a <= 'Z')a = 'a' + (a - 'A');
    for (int i(0); i < 10; ++i) {
        for (int j(0); j < tab[i].size(); ++j) {
            if (a == tab[i][j]) {
                pos = j;
                return i;
            }
        }
    }
}

void same_kind(char a, char b)//0 ('a'-'z') (' ') (',') ('.') ('!') 1 ('A'-'Z') 2('0'-'9')
{
    int numa = get_kind(a);
    int numb = get_kind(b);
    if ((numb == 0 && numa == 1) ||
        (numb == 1 && numa == 0)) {
        cout << "*";
    } else {
        if ((numb == 0 && numa == 2) ||
            (numb == 2 && numa == 0) ||
            (numb == 1 && numa == 2) ||
            (numb == 2 && numa == 1)) {
            cout << "#";
            if (numb == 1 && numa == 2)cout << "*";
        }
    }
}

void same_key(char a, char b) {
    int pos = 0, nn = 0;
    int keya = get_key(a, pos);
    int keyb = get_key(b, nn);
    for (int i(0); i <= pos; ++i)cout << keya;
    if (keya == keyb) {
        if (!(b <= '9' && b >= '0'))cout << "ok";
    }
}

int main() {
    //freopen("temp.txt","w+",stdout);
    //freopen("tempin.txt","r",stdin);
    string data;
    char now[1004];
    ini();
    while (getline(cin, data)) {
        now[0] = 'a';
        for (int i(0); i < data.length(); ++i)now[i + 1] = data[i];
        now[data.length() + 1] = now[data.length()];
        for (int i(1); i <= data.length(); ++i) {
            int j = i - 1;
            int k = i + 1;
            same_kind(now[j], now[i]);
            if (get_kind(now[i]) == 2) {
                cout << now[i];
            } else {
                same_key(now[i], now[k]);
            }
        }
        cout << endl;
    }
    return 0;
}
