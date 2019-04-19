#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <set>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

int gcd(int a, int b) {
    int t;
    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int d[10000005];

class BalanceScale {
public:
    int takeWeights(vector<int> w) {
        int i, tmp;
        int n = w.size();
        tmp = w[0];
        for (i = 1; i < n; ++i) {
            tmp = gcd(tmp, w[i]);
        }
        for (i = 0; i < n; ++i) {
            w[i] /= tmp;
        }
        sort(w.begin(), w.end());
        if (w[0] == 1) return 1;
        memset(d, 1, sizeof(d));
        queue<int> q;
        for (i = 0; i < n; ++i) {
            q.push(w[i]);
            d[w[i]] = 1;
        }
        while (!q.empty() && d[1] == 0x01010101) {
            int top = q.front();
            q.pop();
            for (i = 0; i < n; ++i) {
                tmp = gcd(top, w[i]);
                if (d[tmp] == 0x01010101) {
                    d[tmp] = d[top] + 1;
                    q.push(tmp);
                }
            }
        }
        return d[1];
    }
};

int main() {
    int n;
    vector<int> w;
    BalanceScale solution;
    while (cin >> n, n) {
        w.clear();
        int data;
        for (int i = 0; i < n; ++i) {
            cin >> data;
            w.push_back(data);
        }
        cout << solution.takeWeights(w) << endl;
    }
    return 0;
}