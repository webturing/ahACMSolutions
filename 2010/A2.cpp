//
// Created by jal on 2019-04-25.
//

#include<bits/stdc++.h>

using namespace std;

int main() {
    string s1;
    string s2;
    while(getline(cin, s1)){
        getline(cin, s2);
        for (auto &i : s1) {
            if(isupper(i)){
                i += 32;
            }
        }
        for (auto &i : s2){
            if(isupper(i)){
                i += 32;
            }
        }
        int k = s2.find(s1, 0);
        int cnt = 0;
        while(k != string::npos){
            k = s2.find(s1, k + s1.size());
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
