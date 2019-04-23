#include<iostream>
#include<cstdio>
#define N 100005
using namespace std;
//rmq 或 线段树都可以
struct Tree
{
    int l,r;
    int lv,rv,mv;
} tree[4*N];
int a[N];
void PushUp(int l,int r,int idx)
{
    tree[idx].lv = tree[idx<<1].lv;
    tree[idx].rv = tree[idx<<1|1].rv;
    tree[idx].mv = max(tree[idx<<1].mv,tree[idx<<1|1].mv);
    int mid=(l+r)>>1;
    int len = r-l+1;
    if(a[mid]<a[mid+1])
    {
        if(tree[idx].lv==len-(len>>1))
            tree[idx].lv +=tree[idx<<1|1].lv;
        if(tree[idx].rv==(len>>1))
            tree[idx].rv +=tree[idx<<1].rv;
        tree[idx].mv = max(tree[idx].mv,tree[idx<<1].rv+tree[idx<<1|1].lv);
    }
}
void build(int l,int r,int idx)
{
    tree[idx].l = l;
    tree[idx].r = r;
    if(l==r)
    {
        tree[idx].lv = tree[idx].rv = tree[idx].mv = 1;
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,idx<<1);
    build(mid+1,r,idx<<1|1);
    PushUp(l,r,idx);
}
int query(int l,int r,int idx)
{
    if(tree[idx].l>=l&&tree[idx].r<=r)
    {
        return tree[idx].mv;
    }
    int mid=(tree[idx].l+tree[idx].r)>>1;
    int ans = 0;
    if(l<=mid)
        ans = max(ans,query(l,r,idx<<1));
    if(r>mid)
        ans = max(ans,query(l,r,idx<<1|1));
    if(a[mid]<a[mid+1])
    {
        ans = max(ans,min(mid-l+1,tree[idx<<1].rv)+min(r-mid,tree[idx<<1|1].lv));
    }
    return ans;
}
void work()
{
    int n,m;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        build(1,n,1);
        while(m--)
        {
            int b,c;
            scanf("%d%d",&b,&c);
            printf("%d\n",query(b,c,1));
        }
    }
}
int main()
{
    work();
    return 0;
}
