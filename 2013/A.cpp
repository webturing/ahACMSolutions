#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

bool isChar(char ch) {
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

int main() {
    string s = "";
    string word = "";
    char ch;
    int cnt = 0;
    while (true) {
        getline(cin, s);
        if (s.size() == 0) {
            break;
        }
        word = "";
        int i, j, k;
        for (i = 0; i < s.size();) {
            if (isChar(s[i])) {
                word = "";
                word += s[i];

                for (j = i + 1; j < s.size(); ++j) {
                    if (isChar(s[j])) {
                        word += s[j];
                    } else {
                        break;
                    }
                }
                for (k = word.size() - 1; k >= 0; --k) {
                    cout << word[k];
                }
                if (j >= s.size()) {
                    break;
                } else {
                    cout << s[j];
                }
                i = j + 1;
            } else {
                cout << s[i];
                i++;
            }
        }
        cout << endl;
    }
    return 0;
}
