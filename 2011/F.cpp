#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

struct people {
    int a;
    int b;
    int c;
};

bool cmp(people A, people B) {
    if (A.a < B.a && A.b < B.b && A.c < B.c)
        return true;
    return false;
}

int main() {
    int n;
    while (cin >> n) {
        people women[n];
        for (int i = 0; i < n; i++)
            cin >> women[i].a;
        for (int i = 0; i < n; i++)
            cin >> women[i].b;
        for (int i = 0; i < n; i++)
            cin >> women[i].c;

        sort(women, women + n, cmp);
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
            if (women[i].a < women[i + 1].a && women[i].b < women[i + 1].b && women[i].c < women[i + 1].c)
                sum++;
        cout << sum << endl;
    }

    return 0;
}