//
// Created by webturing on 2019/5/19.
//

#include<bits/stdc++.h>

using namespace std;

//2019ahcpc热身赛第一题： 喝个够
//n瓶饮料 m个空瓶可以换一瓶饮料 问这个人最多可以喝多少瓶
//直接模拟
int main() {
    int n, m;
    cin >> n >> m;
    int tot = n;//先把n瓶喝完
    while (true) {
        int bot = n / m;//兑换
        tot += bot;
        bot += n % m;//第一次余下的瓶子
        if (bot < m)break;//无法兑换就退出
        n = bot;
    }
    cout << tot << endl;
    return 0;

}
