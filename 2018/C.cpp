#include<bits/stdc++.h>

using namespace std;
#define maxn 100050
#define inf 0x3f3f3f3f
int A[maxn];
void work() //ÈýÖ¸ÕëÉ¨Ãè
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>A[i];
        }
        int Ai = n-2,Aj=n-1,Ak=n;
        int ans = max(0,A[Ai]-A[Aj])+max(0,A[Aj]-A[Ak]);
        while(Ai>0)
        {
            ans = max(ans,max(0,A[Ai]-A[Aj])+max(0,A[Aj]-A[Ak]));
            while(Aj>Ai)
            {
                int temp = max(0,A[Ai]-A[Aj])+max(0,A[Aj]-A[Ak]);
                if(temp>ans)
                {
                    ans = temp;
                    break;
                }
                if(Aj-1!=Ai)
                    Aj--;
                else
                    break;
            }
            while(Ak>Aj)
            {
                int temp = max(0,A[Ai]-A[Aj])+max(0,A[Aj]-A[Ak]);
                if(temp>ans)
                {
                    ans = temp;
                    break;
                }
                if(Ak-1!=Aj)
                    Ak--;
                else
                    break;
            }
            Ai--;
        }
        cout<<ans<<endl;
    }
}
int main()
{
    work();
    return 0;
}
