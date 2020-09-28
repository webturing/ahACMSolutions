#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define endl '\n'
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

template<typename T>
void OOM(T a, string s = "") {
    cerr << s << ":";
    for (auto e:a) cerr << e.first << "," << e.second << " ";
    cerr << endl;
}

template<typename T>
void OO(T a, string s = "") {
    cerr << s << ":";
    for (auto e:a)cerr << e << " ";
    cerr << endl;
}

template<typename T>
inline void oo(string str, T val) { cerr << str << val << endl; }

template<typename T>
inline T read() {
    T x;
    cin >> x;
    return x;
}

int main() {
    set<pair<char, int>> S;
    string str("PKHT");
    for (auto c : str) {
        for (int i = 1; i <= 13; i++) {
            S.insert(make_pair(c, i));
        }
    }
    string t(read<string>());
    bool flag = true;
    for (int i = 0; i < t.size() / 3; i++) {
        char c = t[i * 3];
        int d = (t[i * 3 + 1] - '0') * 10 + t[i * 3 + 2] - '0';
        pair<char, int> p = {c, d};
        if (S.find(p) == S.end()) {
            cout << "GRESKA" << endl;
            flag = false;
            break;
        } else {
            S.erase(p);
        }
    }
    if (flag) {
        for (auto c : str) {
            cout << count_if(S.begin(), S.end(), [c](pair<char, int> pa) -> bool { return pa.first == c; }) << endl;
        }
    }
    return 0;
}
 