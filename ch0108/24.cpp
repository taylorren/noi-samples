#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int MAX=15;
    int n, i, j, t;
    cin>>n;

    int a[MAX][MAX];
    int k;
    int flag;

    t = 0;
    for (k = 0; k < n; k++) // 填充左上三角部分（包括主对角线）
    {
        if ((k & 1) == 0) // 第奇数个斜排，从左下往右上扫描填充
        {
            i = k;
            j = 0;
            for (; i >= 0; i--, j++)
            {
                t++;
                a[i][j] = t;
            }
        }
        else // 第偶数个斜排，从右上往左下扫描填充
        {
            i = 0;
            j = k;
            for (; j >= 0; i++, j--)
            {
                t++;
                a[i][j] = t;
            }
        }
    }

    if ((n & 1) == 0) // flag等于0或1决定了右下三角部分第一个斜排的方向
        flag = 1;
    else
        flag = 0;
    for (k = 1; k < n; k++) // 右下三角部分（不包括主对角线）
    {
        if (flag == 1) // 从左下往右上扫描填充
        {
            i = n - 1;
            j = k;
            for (; j < n; j++, i--)
            {
                t++;
                a[i][j] = t;
            }
            flag = 0;
        }
        else // 从右上往左下扫描填充
        {
            i = k;
            j = n - 1;
            for (; i < n; i++, j--)
            {
                t++;
                a[i][j] = t;
            }
            flag = 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
