#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef unsigned long long LL;
const int maxn = 25;
int n, A, B;
LL f[maxn][maxn];
/*
    f(i,j)=在前i个盒子里面放不多于j个球的方案数
    f(i,j)=f(i-1,j)+f(i-1,j-1)+...+f(i-1,0);
    Ans=f(n,A)*f(n*B);
    f(0,j)=1; |  0<=j<=max(A,B)
*/
int main()
{
    cin>>n>>A>>B;

    for(int j = 0; j <= A || j <= B; j++)
    {
        f[0][j] = 1;
    }

    for(int i = 1; i <= n; i++) // 观察到f(i,j)=sigma(f(i-1,x)) | 0<=x<=j。填表的时候只用上面一行,所以前缀和优化
    {
        LL t = 0;
        for(int j = 0; j <= max(A, B); j++)
        {
            t += f[i - 1][j];
            f[i][j] = t;
        }
    }

    cout << f[n][A] * f[n][B] << '\n';

    return 0;
}

//https://blog.csdn.net/cqyz_yuyuko/article/details/52131091