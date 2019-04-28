#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int a[MAXN];
/*
 * 求Ai-Aj 和 Aj-Ak的最大值
 * 可以看成求Ai-Ak的最大值
 * 直接找Ai-Ak的最大值
 */

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1;i <= n;i++)
            cin >> a[i];
        int res = 0, mmin = a[n];
        for (int i = n-1;i >= 1;i--)
        {
            if (a[i] < mmin)
                mmin = a[i];
            else
                res = max(res, a[i]-mmin);
        }
        cout << res << endl;
    }

    return 0;
}