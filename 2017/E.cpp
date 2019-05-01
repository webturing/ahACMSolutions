#include<bits/stdc++.h>

using namespace std;
//×Ö·û´®Ä£Äâ
struct Version
{
    char c[11];
    int flag;
    int b;
    int vis = 0;
};

Version splt(char c[])
{
    Version v;
    v.flag=4;
    int len = strlen(c);
    for(int i=0;i<len;i++)
    {
        if(c[i]=='<')
            v.flag=3;
        else if(c[i]=='>')
            v.flag=4;
        else if(c[i]=='=')
            v.flag-=2;
    }
    v.vis = 0;
    char *ptr = strtok(c," <>=");
    strcpy(v.c,ptr);
    ptr = strtok(NULL," <>=");
    int l = strlen(ptr);
    int m,n,k;
    sscanf(ptr, "%d.%d.%d", &n,&m,&k);
    v.b = n*10000+m*100+k;
    return v;
}
int main()
{
    int T;
    cin>>T;
    int cnt = 1;
    while(cnt<=T)
    {
        int n;
        cin>>n;
        vector<Version> v;
        while(n--)
        {
            char c[100];
            cin>>c;
            Version l = splt(c);
            v.push_back(l);
        }
        cin>>n;
        while(n--)
        {
            char c[11];
            int d,h,k;
            scanf("%s %d.%d.%d",c,&d,&h,&k);
            Version l;
            strcpy(l.c,c);
            l.b = d*10000+h*100+k;
            for(int i=0;i<v.size();i++)
            {
                if(strcmp(v[i].c,l.c)==0)
                {
                    if(v[i].flag==0&&v[i].b==l.b)
                        v[i].vis=1;
                    else if(v[i].flag==1&&l.b<=v[i].b)
                        v[i].vis=1;
                    else if(v[i].flag==2&&l.b>=v[i].b)
                        v[i].vis=1;
                    else if(v[i].flag==3&&l.b<v[i].b)
                        v[i].vis=1;
                    else if(v[i].flag==4&&l.b>v[i].b)
                        v[i].vis=1;
                }
            }
        }
        cout<<"Case "<<cnt<<":";
        int tmp = 0;
        for(auto i : v)
        {
            if(i.vis==0)
            {
                cout<<" "<<i.c;
                tmp++;
            }
        }
        if(tmp ==0)
            cout<<" OK"<<endl;
        else
            cout<<endl;
    }
    return 0;
}
