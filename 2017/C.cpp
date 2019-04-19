#include<stdio.h>
#include<cmath>

int main() {
    int k = 1, t;
    scanf("%d", &t);
    while (k++ <= t) {
        int n, m;
        scanf("%d %d", &n, &m);

        int ticket[100005];
        for (int i = 1; i <= n; i++)
            scanf("%d", ticket + i);

        int j = 1, max = ticket[1];
        for (int i = 2; i <= n; i++)      //判断是否有别的值比ticket[1]大，并找出来
            if (ticket[i] >= max) {
                j = i;
                max = ticket[i];
            }

        if (j == 1)                    //ticket[1]就是最大的
        {
            printf("Case %d: 0\n", k - 1);
            continue;
        }

        if (n == m)                    //n==m且ticket[1] 不是最大的，则无解
        {
            printf("Case %d: Impossible\n", k - 1);
            continue;
        }

        int a = max - ticket[1] + 1;    //为了比最大的人票数多，至少要a个水军参加投票
        int count = a * m - a;          //count 为a个水军投票的总数，去掉给ticket[1]的票

        //把count个票往别的选手上分，但要使得其他人的票数最多为max（ticket[1]-1） ,  
        for (int i = 2; i <= n; i++) {
            if (ticket[i] >= ticket[1]) //最多只能给（max - ticket[i]）个，使的他的票数为max
                count = count - (max - ticket[i]);
            else
                count -= a;
        }

        if (count <= 0)     //如果此时票数分完了，也就是已经够了（上面已经保证每一个都不大于ticket[1]）
        {
            printf("Case %d: %d\n", k - 1, a);
            continue;
        }

        int i;
        //如果不够，继续加水军   
        for (i = 1; (1.0 * i * m + count - i) / (n - 1) >
                    i; i++);    //i个水军吧票数给1号i票之后，把剩下的票数平分给其他的n-1个人，如果他们平均得到的票数<=i(也就是其他人票数要始终比1号少一个或多个)，此时就已经够了
        //i = ceil(count*1.0/(n-m));   上面的for循环可以简化为这个试子
        printf("Case %d: %d\n", k - 1, a + i);
    }
}  