#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int a[n+5];
        for(int i = 0 ; i < n ; i ++)
            cin >> a[i];
        sort(a,a+n);
        int k,flag,cnt=0;
        cin >> k;
        for(int i = n-1 ; i > 0 ; i --){
            if(a[i] != a[i-1])
                cnt ++;
            if(cnt == k){
                flag = i;
                break;
            }
        }
        cout << a[flag] << endl;
    }
    return 0;
}
