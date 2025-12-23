#include <bits/stdc++.h>
using namespace std;

int main()
{
    string x, y;
    cin >> x >> y;
    int lenx = x.length(), leny = y.length();
    int tx, ty;
    // 记录小数点位置
    for (int i = 0; i < lenx; i++)
    {
        if (x[i] == '.')
        {
            tx = i;
            break;
        }
    }
    for (int i = 0; i < leny; i++)
    {
        if (y[i] == '.')
        {
            ty = i;
            break;
        }
    }
    // 小数点对齐
    while (tx < ty)
    {
        x = '0' + x;
        tx++;
        lenx++;
    }
    while (ty < tx)
    {
        y = '0' + y;
        ty++;
        leny++;
    }
    // 等号对齐
    while (lenx < leny)
    {
        x = x + '0';
        lenx++;
    }
    while (leny < lenx)
    {
        y = y + '0';
        leny++;
    }
    int len = x.length();
    int flag = 0;
    // 小数加法
    for (int i = len - 1; i > tx; i--)
    {
        x[i] = x[i] - '0' + y[i];
        if (x[i] > '9')
        {
            x[i] = (x[i] - '0') % 10 + '0';
            if (i == tx + 1)
                flag = 1;
            else
                x[i - 1] = x[i - 1] + 1;
        }
    }
    // 小数向整数有进位
    if (flag)
        x[tx - 1] = x[tx - 1] + 1;
    // 整数加法
    for (int i = tx - 1; i > 0; i--)
    {
        x[i] = x[i] - '0' + y[i];
        if (x[i] > '9')
        {
            x[i] = (x[i] - '0') % 10 + '0';
            x[i - 1] = x[i - 1] + 1;
        }
    }
    x[0] = x[0] - '0' + y[0];
    if (x[0] > '9')
    {
        x[0] = (x[0] - '0') % 10 + '0';
        x = '1' + x;
    }
    // 去掉小数末尾的0
    int ans = lenx;
    for (int i = lenx - 1; i >= 0; i--)
    {
        if (x[i] == '0')
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < ans; i++)
    {
        cout << x[i];
    }
    return 0;
}