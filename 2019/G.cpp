#include<iostream>
#include<ctime>

using namespace std;
long long dp[1003][1003] = {0}, m;

int main() {
    int n;
    cin >> n >> m;
    n = n / 2;
    int i, j, pos;

    for (i = 0; i < n; i++)//求出dp数组
    {
        for (j = i; j < n; j++) {
            if (i == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
        if (m - dp[i][n - 1] <= 0)//求出的情况包含M就停止
        {
            pos = i;
            break;//pos记录位置（0,1,2,3）
        } else {
            m -= dp[i][n - 1];//否则M在剩余情况继续计算
        }
    }
    char str[2003] = {0};
    int x = pos, y = n - 1, p = 0;
    for (; p < n - pos; p++)//添加已知的左括号和一个右括号
    {
        str[p] = '(';
    }
    str[p] = ')';
    p++;
    while (1)//求解剩余的序列
    {
        if (x == 0)//此时只需补全右括号即可完成序列
        {
            while (y > 0) {
                str[p] = ')';
                p++;
                y--;
            }
            break;
        }
        if (dp[x - 1][y] >= m)//向左走，添加左括号
        {
            x--;
            str[p] = '(';
            p++;
            continue;
        }
        if (dp[x - 1][y] < m)//向下走，添加右括号
        {
            m -= dp[x - 1][y];
            y--;
            str[p] = ')';
            p++;
            continue;
        }
    }
    for (j = 0; j <= p - 1; j++) {
        cout << str[j];
    }
    return 0;
}