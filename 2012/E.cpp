#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;
#define ONLINE_JUDGE

void solve() {
    int test;
    int cas = 1;
    int n;
    for (cin >> test; test--; ++cas) {
        cin >> n;
        cout << "Case #" << cas << ": " << ((n) & (-n)) << endl;
    }
    return;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("E.in", "r", stdin);
 freopen("E.out", "w", stdout);
#endif
    solve();
    return EXIT_SUCCESS;
}