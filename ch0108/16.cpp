#include <bits/stdc++.h>
using namespace std;
char a[110][110], b[110][110];
int n, m, t;
int main()
{
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];    // 输入给定矩阵
            b[i][j] = a[i][j]; // 把a数组复制到b数组这样就能解决平局问题
        }
    }
    for (int k = 1; k <= t; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == 'R')
                { // 石头永远胜剪刀，所以如果石头其上下左右有一位置是剪刀，那么剪刀的位置将被石头占领，所以输出石头
                    if (a[i - 1][j] == 'S')
                    {
                        b[i - 1][j] = 'R';
                    }
                    if (a[i + 1][j] == 'S')
                    {
                        b[i + 1][j] = 'R';
                    }
                    if (a[i][j - 1] == 'S')
                    {
                        b[i][j - 1] = 'R';
                    }
                    if (a[i][j + 1] == 'S')
                    {
                        b[i][j + 1] = 'R';
                    }
                }
                if (a[i][j] == 'S')
                { // 剪刀永远胜布，所以如果剪刀其上下左右有一位置是布，那么布的位置将被剪刀占领，所以输出剪刀
                    if (a[i - 1][j] == 'P')
                    {
                        b[i - 1][j] = 'S';
                    }
                    if (a[i + 1][j] == 'P')
                    {
                        b[i + 1][j] = 'S';
                    }
                    if (a[i][j - 1] == 'P')
                    {
                        b[i][j - 1] = 'S';
                    }
                    if (a[i][j + 1] == 'P')
                    {
                        b[i][j + 1] = 'S';
                    }
                }
                if (a[i][j] == 'P')
                { // 布永远胜石头，所以如果布其上下左右有一位置是石头，那么石头的位置将被布占领，所以输出布
                    if (a[i - 1][j] == 'R')
                    {
                        b[i - 1][j] = 'P';
                    }
                    if (a[i + 1][j] == 'R')
                    {
                        b[i + 1][j] = 'P';
                    }
                    if (a[i][j - 1] == 'R')
                    {
                        b[i][j - 1] = 'P';
                    }
                    if (a[i][j + 1] == 'R')
                    {
                        b[i][j + 1] = 'P';
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                a[i][j] = b[i][j]; // 把b数组复制到a数组
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << b[i][j]; // 输出b数组
        }
        cout << endl; // 每输出n行，就换行接着输出
    }
    return 0;
}
