//
// Created by webturing on 4/23/19.
//

#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int ans[100005];

bool check(int k);

int main(void) {
    int t;
    scanf("%d", &t);

    int sum;
    while (t--) {
        sum = 0;
        int minn = 0x3f3f3f3f;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &ans[i]);
            minn = min(minn, ans[i]);
            sum += ans[i];
        }

        int l = minn;
        int r = sum;
        int mid, res;
        while (l <= r) {
            mid = (l + r) / 2;
            if (check(mid)) {
                l = mid + 1;
                res = mid;
            } else {
                r = mid - 1;
            }

        }
        printf("%d\n", res - 1);
    }

    return 0;
}

bool check(int k) {
    int num = 1;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (cnt + ans[i] <= k) {
            cnt += ans[i];
        } else {
            num++;
            cnt = ans[i];
        }
    }
    if (num > m)
        return true;
    else
        return false;
}
