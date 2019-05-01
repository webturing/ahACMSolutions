#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
//简单的模拟，注意条件： 其能承受的最大值15A、只有一个二插插口（该插口可承受无穷大电流量）
int main()
{
    int T, n, m;
    double I, sum;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        cin >> n >> m;
        sum = 0.0;
        for(int i = 0; i < n; ++i) {
            cin >> I;
            sum += I;
        }
        if(n == 1 || n == 0) {
            cout << "Case " << t << ": yes" << endl;
            continue;
        }
        if(n > (2*m+1)) {
            cout << "Case " << t << ": no" << endl;
            continue;
        }
        if(sum > 15.0) {
            cout << "Case " << t << ": no" << endl;
            continue;
        }
        cout << "Case " << t << ": yes" << endl;
    }
    return 0;
}
