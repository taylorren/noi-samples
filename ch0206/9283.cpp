#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll f[20][20], c[20][20], a[20];
int T, n[110], m;

void solve()
{
    // 初始化组合数数组
    memset(c, 0, sizeof(c));
    for(int i = 0; i <= m; ++i)
    {
        c[i][0] = 1;  // 从i个元素中选0个的方法只有1种
        for(int j = 1; j <= i; ++j)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }

    // 初始化f数组
    memset(f, 0, sizeof(f));
    f[1][1] = 1;

    // 计算f[i][j]
    for(int i = 2; i <= m; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            if(j == 0)
            {
                f[i][j] = 0;  // 选0个组合的方法数为0
            }
            else if(j == 1)
            {
                f[i][j] = 1;  // 选1个组合的方法数为1
            }
            else
            {
                f[i][j] = f[i - 1][j] * j + f[i - 1][j - 1];
            }
        }
    }

    // 计算阶乘
    a[0] = 1;  // 0的阶乘为1
    a[1] = 1;
    for(int i = 2; i <= m; ++i)
    {
        a[i] = a[i - 1] * i;
    }
}

int main()
{
    int i, j;
    cin >> T;
    m = 0;  // 初始化m为0
    for(i = 1; i <= T; ++i)
    {
        cin >> n[i];
        m = max(m, n[i]);
    }

    solve();
    for(int l = 1; l <= T; ++l)
    {
        ll ans = 0;
        for(i = 1; i <= n[l]; ++i)
        {
            for(j = 1; j <= i; ++j)
            {
                ans += c[n[l]][i] * f[i][j] * a[j];
            }
        }
        printf("%d %d %lld\n", l, n[l], ans);
    }
    return 0;
}