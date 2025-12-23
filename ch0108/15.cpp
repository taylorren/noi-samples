#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[10][10], b[10][10], n;
    cin >> a[5][5] >> n;
    b[5][5] = a[5][5];
    for (int i = 1; i <= 9; i++)
    {
        for (int k = 1; k <= 9; k++)
        {
            if (i != 5 or k != 5)
            { // 将数组中心赋值为m，其余赋值为0
                a[i][k] = 0;
                b[i][k] = 0;
            }
        }
    }
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= 9; i++)
        {
            for (int k = 1; k <= 9; k++)
            { // 计算每一次繁殖数据，中间格子数量*2，周围格子加上中间格子原有数量
                if (a[i][k] > 0)
                {
                    b[i][k] = b[i][k] + a[i][k];
                    b[i - 1][k - 1] = b[i - 1][k - 1] + a[i][k];
                    b[i - 1][k] = b[i - 1][k] + a[i][k];
                    b[i - 1][k + 1] = b[i - 1][k + 1] + a[i][k];
                    b[i][k - 1] = b[i][k - 1] + a[i][k];
                    b[i][k + 1] = b[i][k + 1] + a[i][k];
                    b[i + 1][k - 1] = b[i + 1][k - 1] + a[i][k];
                    b[i + 1][k] = b[i + 1][k] + a[i][k];
                    b[i + 1][k + 1] = b[i + 1][k + 1] + a[i][k];
                }
            }
        }
        for (int i = 1; i <= 9; i++)
        { // 将每一次繁殖数据同步至另一个数组
            for (int k = 1; k <= 9; k++)
            {
                a[i][k] = b[i][k];
            }
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        for (int k = 1; k <= 9; k++)
        { // 输出
            cout << a[i][k] << " ";
        }
        cout << endl;
    }
    return 0;
}