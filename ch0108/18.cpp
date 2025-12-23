#include <bits/stdc++.h>
using namespace std;
int a[1001][1001], now = 1, tot = 0, hang, lie, l_h, l_l, ans = 0;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1][j] == 0 && a[i - 1][j - 1] == 0 && a[i][j - 1] == 0 && i != 1 && j != 1)
            { // 找到他们的左上角
                hang = i;
                lie = j;
                break;
            }
        }
    }
    
    for (int j = lie; j <= n; j++)
    {
        if (a[hang][j] != 0)
        { // 查看列的长度
            l_l++;
        }
        else
            break;
    }
    
    for (int i = hang; i <= n; i++)
    {
        if (a[i][lie] != 0)
        { // 查看行的长度
            l_h++;
        }
        else
            break;
    }
    
    cout << l_h * l_l; // 输出长乘宽的面积
    return 0;
}