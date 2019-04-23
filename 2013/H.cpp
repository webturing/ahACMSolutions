#include<cstdio>
#include<memory>
#include<string>
#include<iostream>

using namespace std;


//´óÊý
#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4

class BigNum {
private:
    int a[500];    //¿ÉÒÔ¿ØÖÆ´óÊýµÄÎ»Êý
    int len;       //´óÊý³¤¶È
public:
    BigNum() {
        len = 1;
        memset(a, 0, sizeof(a));
    }   //¹¹Ôìº¯Êý
    BigNum(const int);       //½«Ò»¸öintÀàÐÍµÄ±äÁ¿×ª»¯Îª´óÊý
    BigNum(const char *);     //½«Ò»¸ö×Ö·û´®ÀàÐÍµÄ±äÁ¿×ª»¯Îª´óÊý
    BigNum(const BigNum &);  //¿½±´¹¹Ôìº¯Êý
    BigNum &operator=(const BigNum &);   //ÖØÔØ¸³ÖµÔËËã·û£¬´óÊýÖ®¼ä½øÐÐ¸³ÖµÔËËã

    friend istream &operator>>(istream &, BigNum &);   //ÖØÔØÊäÈëÔËËã·û
    friend ostream &operator<<(ostream &, BigNum &);   //ÖØÔØÊä³öÔËËã·û

    BigNum operator+(const BigNum &) const;   //ÖØÔØ¼Ó·¨ÔËËã·û£¬Á½¸ö´óÊýÖ®¼äµÄÏà¼ÓÔËËã
    BigNum operator-(const BigNum &) const;   //ÖØÔØ¼õ·¨ÔËËã·û£¬Á½¸ö´óÊýÖ®¼äµÄÏà¼õÔËËã
    BigNum operator*(const BigNum &) const;   //ÖØÔØ³Ë·¨ÔËËã·û£¬Á½¸ö´óÊýÖ®¼äµÄÏà³ËÔËËã
    BigNum operator/(const int &) const;    //ÖØÔØ³ý·¨ÔËËã·û£¬´óÊý¶ÔÒ»¸öÕûÊý½øÐÐÏà³ýÔËËã
    BigNum operator*(const int &) const;

    BigNum operator+(const int &) const;

    BigNum operator^(const int &) const;    //´óÊýµÄn´Î·½ÔËËã
    int operator%(const int &) const;    //´óÊý¶ÔÒ»¸öintÀàÐÍµÄ±äÁ¿½øÐÐÈ¡Ä£ÔËËã
    bool operator>(const BigNum &T) const;   //´óÊýºÍÁíÒ»¸ö´óÊýµÄ´óÐ¡±È½Ï
    bool operator>(const int &t) const;      //´óÊýºÍÒ»¸öintÀàÐÍµÄ±äÁ¿µÄ´óÐ¡±È½Ï
    bool operator==(const BigNum &T) const;   //´óÊýºÍÁíÒ»¸ö´óÊýµÄÏàµÈ±È½Ï
    bool operator==(const int &t) const;      //´óÊýºÍÒ»¸öintÀàÐÍµÄ±äÁ¿µÄÏàµÈ±È½Ï
    void print();       //Êä³ö´óÊý
};

BigNum::BigNum(const int b)     //½«Ò»¸öintÀàÐÍµÄ±äÁ¿×ª»¯Îª´óÊý
{
    int c, d = b;
    len = 0;
    memset(a, 0, sizeof(a));
    while (d > MAXN) {
        c = d - (d / (MAXN + 1)) * (MAXN + 1);
        d = d / (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}

BigNum::BigNum(const char *s)     //½«Ò»¸ö×Ö·û´®ÀàÐÍµÄ±äÁ¿×ª»¯Îª´óÊý
{
    int t, k, index, l, i;
    memset(a, 0, sizeof(a));
    l = strlen(s);
    len = l / DLEN;
    if (l % DLEN)
        len++;
    index = 0;
    for (i = l - 1; i >= 0; i -= DLEN) {
        t = 0;
        k = i - DLEN + 1;
        if (k < 0)
            k = 0;
        for (int j = k; j <= i; j++)
            t = t * 10 + s[j] - '0';
        a[index++] = t;
    }
}

BigNum::BigNum(const BigNum &T) : len(T.len)  //¿½±´¹¹Ôìº¯Êý
{
    int i;
    memset(a, 0, sizeof(a));
    for (i = 0; i < len; i++)
        a[i] = T.a[i];
}

BigNum &BigNum::operator=(const BigNum &n)   //ÖØÔØ¸³ÖµÔËËã·û£¬´óÊýÖ®¼ä½øÐÐ¸³ÖµÔËËã
{
    int i;
    len = n.len;
    memset(a, 0, sizeof(a));
    for (i = 0; i < len; i++)
        a[i] = n.a[i];
    return *this;
}

istream &operator>>(istream &in, BigNum &b)   //ÖØÔØÊäÈëÔËËã·û
{
    char ch[MAXSIZE * 4];
    int i = -1;
    in >> ch;
    int l = strlen(ch);
    int count = 0, sum = 0;
    for (i = l - 1; i >= 0;) {
        sum = 0;
        int t = 1;
        for (int j = 0; j < 4 && i >= 0; j++, i--, t *= 10) {
            sum += (ch[i] - '0') * t;
        }
        b.a[count] = sum;
        count++;
    }
    b.len = count++;
    return in;

}

ostream &operator<<(ostream &out, BigNum &b)   //ÖØÔØÊä³öÔËËã·û
{
    int i;
    cout << b.a[b.len - 1];
    for (i = b.len - 2; i >= 0; i--) {
        cout.width(DLEN);
        cout.fill('0');
        cout << b.a[i];
    }
    return out;
}

BigNum BigNum::operator+(const BigNum &T) const   //Á½¸ö´óÊýÖ®¼äµÄÏà¼ÓÔËËã
{
    BigNum t(*this);
    int i, big;      //Î»Êý
    big = T.len > len ? T.len : len;
    for (i = 0; i < big; i++) {
        t.a[i] += T.a[i];
        if (t.a[i] > MAXN) {
            t.a[i + 1]++;
            t.a[i] -= MAXN + 1;
        }
    }
    if (t.a[big] != 0)
        t.len = big + 1;
    else
        t.len = big;
    return t;
}

BigNum BigNum::operator-(const BigNum &T) const   //Á½¸ö´óÊýÖ®¼äµÄÏà¼õÔËËã
{
    int i, j, big;
    bool flag;
    BigNum t1, t2;
    if (*this > T) {
        t1 = *this;
        t2 = T;
        flag = 0;
    } else {
        t1 = T;
        t2 = *this;
        flag = 1;
    }
    big = t1.len;
    for (i = 0; i < big; i++) {
        if (t1.a[i] < t2.a[i]) {
            j = i + 1;
            while (t1.a[j] == 0)
                j++;
            t1.a[j--]--;
            while (j > i)
                t1.a[j--] += MAXN;
            t1.a[i] += MAXN + 1 - t2.a[i];
        } else
            t1.a[i] -= t2.a[i];
    }
    t1.len = big;
    while (t1.a[len - 1] == 0 && t1.len > 1) {
        t1.len--;
        big--;
    }
    if (flag)
        t1.a[big - 1] = 0 - t1.a[big - 1];
    return t1;
}

BigNum BigNum::operator*(const BigNum &T) const   //Á½¸ö´óÊýÖ®¼äµÄÏà³ËÔËËã
{
    BigNum ret;
    int i, j, up;
    int temp, temp1;
    for (i = 0; i < len; i++) {
        up = 0;
        for (j = 0; j < T.len; j++) {
            temp = a[i] * T.a[j] + ret.a[i + j] + up;
            if (temp > MAXN) {
                temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
                up = temp / (MAXN + 1);
                ret.a[i + j] = temp1;
            } else {
                up = 0;
                ret.a[i + j] = temp;
            }
        }
        if (up != 0)
            ret.a[i + j] = up;
    }
    ret.len = i + j;
    while (ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    return ret;
}

BigNum BigNum::operator/(const int &b) const   //´óÊý¶ÔÒ»¸öÕûÊý½øÐÐÏà³ýÔËËã
{
    BigNum ret;
    int i, down = 0;
    for (i = len - 1; i >= 0; i--) {
        ret.a[i] = (a[i] + down * (MAXN + 1)) / b;
        down = a[i] + down * (MAXN + 1) - ret.a[i] * b;
    }
    ret.len = len;
    while (ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    return ret;
}

BigNum BigNum::operator*(const int &t) const   //´óÊý¶ÔÒ»¸öÕûÊý½øÐÐÏà³ýÔËËã
{
    BigNum b(t);
    return *this * b;
}

BigNum BigNum::operator+(const int &t) const   //´óÊý¶ÔÒ»¸öÕûÊý½øÐÐÏà³ýÔËËã
{
    BigNum b(t);
    return *this + b;
}

int BigNum::operator%(const int &b) const    //´óÊý¶ÔÒ»¸öintÀàÐÍµÄ±äÁ¿½øÐÐÈ¡Ä£ÔËËã
{
    int i, d = 0;
    for (i = len - 1; i >= 0; i--) {
        d = ((d * (MAXN + 1)) % b + a[i]) % b;
    }
    return d;
}

BigNum BigNum::operator^(const int &n) const    //´óÊýµÄn´Î·½ÔËËã
{
    BigNum t, ret(1);
    int i;
    if (n < 0)
        exit(-1);
    if (n == 0)
        return 1;
    if (n == 1)
        return *this;
    int m = n;
    while (m > 1) {
        t = *this;
        for (i = 1; i << 1 <= m; i <<= 1) {
            t = t * t;
        }
        m -= i;
        ret = ret * t;
        if (m == 1)
            ret = ret * (*this);
    }
    return ret;
}

bool BigNum::operator>(const BigNum &T) const   //´óÊýºÍÁíÒ»¸ö´óÊýµÄ´óÐ¡±È½Ï
{
    int ln;
    if (len > T.len)
        return true;
    else if (len == T.len) {
        ln = len - 1;
        while (a[ln] == T.a[ln] && ln >= 0)
            ln--;
        if (ln >= 0 && a[ln] > T.a[ln])
            return true;
        else
            return false;
    } else
        return false;
}

bool BigNum::operator>(const int &t) const    //´óÊýºÍÒ»¸öintÀàÐÍµÄ±äÁ¿µÄÏàµÈ±È½Ï
{
    BigNum b(t);
    return *this > b;
}

bool BigNum::operator==(const BigNum &T) const   //´óÊýºÍÁíÒ»¸ö´óÊýµÄ´óÐ¡±È½Ï
{
    int ln;
    if (len != T.len)
        return false;
    else {
        ln = len - 1;
        while (ln >= 0 && a[ln] == T.a[ln])
            ln--;
        if (ln >= 0)
            return false;
        else
            return true;
    }
}

bool BigNum::operator==(const int &t) const    //´óÊýºÍÒ»¸öintÀàÐÍµÄ±äÁ¿µÄÏàµÈ±È½Ï
{
    BigNum b(t);
    return *this > b;
}

void BigNum::print() {
    int i;
    cout << a[len - 1];
    for (i = len - 2; i >= 0; i--) {
        cout.width(DLEN);
        cout.fill('0');
        cout << a[i];
    }
    cout << endl;
}

//´óÊý½áÊø

BigNum n;
BigNum x;
BigNum y;
string s;
int len;


BigNum fact(BigNum n) {
    if (n == BigNum(1)) return BigNum(1);
    return n * fact(n - 1);
}

BigNum toNum(string s) {
    bool b[27];
    BigNum ret = 0;
    memset(b, 1, sizeof(b));
    for (int i = 0; i < len; i++) {
        int sum = 0;
        b[s[i] - 'A'] = 0;
        for (int j = 0; j < s[i] - 'A'; j++) {
            sum += b[j];
        }
        ret = ret * (len - i) + sum;
    }
    return ret;
}

void toP(BigNum num) {
    BigNum zz = fact(len);
    bool b[27];
    int a[27];
    for (int i = 0; i < len; i++) {
        a[len - i - 1] = num % (i + 1);
        num = num / (i + 1);
    }
    memset(b, 1, sizeof(b));
    for (int index = 0; index < len - 1; index++) {
        int sum = -1;
        int j;
        for (j = 0; sum < a[index]; j++) {
            sum += b[j];
        }
        j--;
        b[j] = 0;
        cout << (char) ('A' + j);
    }
    int j = -1;
    while (!b[++j]);
    cout << (char) ('A' + j) << endl;
}

int main() {
    char nn[99];
    bool flag;
    BigNum temp;
    while (cin >> s >> nn) {
        if (nn[0] == '-') {
            flag = 0;
            n = BigNum(nn + 1);
        } else {
            flag = 1;
            n = BigNum(nn);
        }
        len = s.size();
        x = toNum(s);
        if (flag && x + n > fact(len) - 1) {
            cout << "Are you kidding me." << endl;
        } else if (!flag && n > x) {
            cout << "Are you kidding me." << endl;
        } else {
            if (flag)
                y = x + n;
            else
                y = x - n;
//            y.print();
            toP(y);
        }
    }
}

