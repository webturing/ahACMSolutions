#include <bits/stdc++.h>
using namespace std;
const int MAX = 10010;
int du[MAX];
int head[MAX];
struct Edge{
    int u,v,to,next;
};
Edge edges[MAX];
int edgeCnt = 0;
void addEdge(int u, int v){
    edges[edgeCnt].v = v;
    edges[edgeCnt].next = head[u];
    head[u] = edgeCnt++;
}
int main(){
    ifstream cin("input.txt");
    int t;
    cin >> t;
    while(t--){
        int m = 0;
        int n;
        cin >> n;
        map<string, int>mp;
        edgeCnt = 0;
        memset(head, -1, sizeof(head));
        memset(du, 0, sizeof(du));
        string s1, s2;
        for(int i = 0; i < n; i++){
            cin >> s1 >> s2;
            if(mp[s1]==0){
                mp[s1] = ++m;
            }
            if(mp[s2]==0){
                mp[s2] = ++m;
            }
            addEdge(mp[s2], mp[s1]);
            du[mp[s1]]++;
        }
        queue<int>q;
        for(int i = 1; i <= m; i++){
            if(du[i]==0){
                q.push(i);
            }
        }
        int cnt = 0;
        while(q.size()>0){
            int u = q.front();
            q.pop();
            cnt++;
            for(int i = head[u]; i!=-1; i = edges[i].next){
                int v = edges[i].v;
                if(!--du[v]){
                    q.push(v);
                }
            }
        }
        if(cnt == m){
            cout << "Passed" << endl;
        }else{
            cout << "Failed" << endl;
        }
    }
}