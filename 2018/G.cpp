#include<bits/stdc++.h>
using namespace std;
const int maxh = 30001;
const int maxn = 5001;
const double loss = 1e-10;
//¼ÇÒä»¯ËÑË÷ + ¼ôÖ¦
struct node
{
    int pos;
    double g;
};
vector<node> v[maxn];
void init()
{
    for(int i=0; i<4; i++)
    {
        node now;
        now.pos = 3+i;
        now.g = 0.25;
        v[1].push_back(now);
    }
    for(int i=2; i<maxn; i++)
    {
        int r = 6*i;
        for(int j=3*i; j<=r; j++)
        {
            node now;
            now.pos = j;
            now.g = 0;
            for(int k=3; k<=6; k++)
            {
                if(j-k>=v[i-1][0].pos && j-k<=v[i-1][v[i-1].size()-1].pos)
                {
                    now.g += 1.0/4*v[i-1][(j-k-v[i-1][0].pos)].g;
                }
            }
            if(now.g>loss)
                v[i].push_back(now);
        }
    }
}
void work()
{
    init();
    int T;
    cin>>T;
    while(T--)
    {
        int n,h;
        cin>>n>>h;
        double ans = 0;
        if(h<=v[n][0].pos)
            printf("%f\n",1.0);
        else if(h>v[n][v[n].size()-1].pos)
            printf("%f\n",0.0);
        else
        {
            for(int i=h-v[n][0].pos;i<v[n].size();i++)
            {
                ans += v[n][i].g;
            }
            printf("%f\n",ans);
        }
    }
}
int main()
{
    work();
    return 0;
}
