#include <iostream>

/*
这题思路上来说很简单，无非就是把物品总价值的最后一位直接进位，
可以(total*100)%10检测最后一位，然后(total*10/10+10)就可以得到要求的数。
但是这里有个问题，C++获取double变量的时候会有精度误差，大小大概为4e-16左右，导致获取到的数如果小数第二位为0，
那么这个数就会变成类似5.0999999999999996这样，
用上面说到的那个方法就会得到错误的答案。解决方法是在获取输入的时候+4e-16这样就会补足那部分差值，然后就可以用正确的数字计算了。
*/
using namespace std;
double bitch(double num){
    int a = num*100;
    if((a%10)!=0)
        a = a/10*10+10;
    return (double)a/100;
}

int main(int argc, const char * argv[]) {
    int T = -1;
    cin >> T;
    double result[100];
    for(int TestTime = 0; TestTime < T; TestTime++){
        int n = -1;
        double total = 0, m = -1;
        cin >> n >> m;
        for(int count = 0; count < n; count++){
            double price = -1;
            int number = -1;
            cin >> price >> number;
            price += 1e-16;
            price *= number;
            total += price;
        }
        total += 1e-8;
        total = bitch(total);
        if(total > m){
            result[TestTime] = -1;
        }
        else{
            result[TestTime] = m-total;
        }
    }
    for(int count = 0; count < T; count++){
        if(result[count] == -1)
            printf("Case %d: -1\n", count+1);
        else
            printf("Case %d: %.2lf\n", count+1, result[count]);
    }
    return 0;
}
