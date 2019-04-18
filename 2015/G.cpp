#include<iostream>
#include<vector>
#include<deque>
#include<cstdio>
#include<cstring>

using namespace std;
struct Edge {
    int to, length;
};

bool spfa(const int &beg, const vector<vector<Edge>> &adjlist, vector<int> &dist, vector<int> &path) {
    const int &INF = 0x7FFFFFFF, &NODE = adjlist.size();
    dist.assign(NODE, INF);
    path.assign(NODE, -1);
    deque<int> que(1, beg);
    vector<bool> flag(NODE, 0);
    vector<int> cnt(NODE, 0);
    dist[beg] = 0;
    ++cnt[beg];
    flag[beg] = 1;
    while (!que.empty()) {
        const int now = que.front();
        que.pop_front();
        flag[now] = 0;
        for (unsigned int i = 0; i != adjlist[now].size(); ++i) {
            const int &next = adjlist[now][i].to;
            if (dist[now] < INF &&
                dist[next] > dist[now] + adjlist[now][i].length) {
                dist[next] = dist[now] + adjlist[now][i].length;
                path[next] = now;
                if (!flag[next]) {
                    if (++cnt[next] == NODE) return 1;
                    if (que.empty() ||
                        dist[next] < dist[que.front()])
                        que.push_front(next);
                    else que.push_back(next);
                    flag[next] = 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int n_num, e_num, beg, mid, T, end, donser[1005];;
    scanf("%d", &T);
    while (T--) {
        cin >> n_num >> e_num;
        memset(donser, 707406378, sizeof(donser));
        vector<vector<Edge> > adjlist(n_num, vector<Edge>());
        for (int i = 0, p; i != e_num; ++i) {
            Edge tmp;
            cin >> p >> tmp.to >> tmp.length;
            adjlist[p].push_back(tmp);
            mid = p;
            p = tmp.to;
            tmp.to = mid;
            adjlist[p].push_back(tmp);
        }
        cin >> beg >> end;
        vector<int> dist, path;
        spfa(end, adjlist, dist, path);
        for (int j = 0; j < n_num; j++) {
            donser[j] = dist[j];
        }
        spfa(beg, adjlist, dist, path);
        for (int j = 0; j < n_num; j++) {
            donser[j] += dist[j];
        }
        mid = 0;
        for (int i = 0; i < n_num; i++) {
            if (donser[i] > mid) mid = donser[i];
        }
        cout << mid << endl;
    }
    return 0;
}