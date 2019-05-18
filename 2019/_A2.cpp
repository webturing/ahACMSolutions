//
// Created by webturing on 2019/5/19.
//

#include<bits/stdc++.h>

using namespace std;

//2019ahcpc热身赛第一题： 喝个够
//n瓶饮料 m个空瓶可以换一瓶饮料 问这个人最多可以喝多少瓶
//数学算法 m个空瓶子可以换一瓶，所以实际上是m-1个瓶子换了一瓶（没有瓶子）的饮料
//考虑到他最后必然手里有一个无法兑换的瓶子所以 n-1
int main() {
    int n, m;
    cin >> n >> m;
    cout << n + (n - 1) / (m - 1) << endl;
    return 0;

}
