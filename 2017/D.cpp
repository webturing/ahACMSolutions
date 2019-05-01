#include<bits/stdc++.h>
using namespace std;
#define Max 10000

int result[Max];
bool CanBuild(int pos, int r)
{
    for (int i = pos - r; i < pos ; i++)
        if (result[i])
            return false;
    return true;
}
int N, M, Sum;
void Build_i(int i)
{
    if (i > N)
        Sum++;
    else
    {
        for (int j = 0; j <= M; j++)
        {
            if (CanBuild(i, j))
            {
                result[i] = j;
                Build_i(i + j + 1);
                result[i] = 0;
            }
            else
                break;
        }
    }
}
int main()
{
    int T;
    cin >> T;
    int *Sums = new int[T];
    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;
        Build_i(1);
        Sums[i] = Sum % 1000000007 ;
        Sum = 0;
        memset(result, 0, Max * sizeof(int));
    }
    for (int i = 0; i < T; i++)
        cout << "Case" << i + 1 << ":" << Sums[i] << endl;
    delete Sums;
    return 0;
}
