#include <iostream>
#include <cmath>
using namespace std;
double a[5];
#define EPS 1e-6 // 10^(-6)，当浮点数小于这个数可认为是0(可以更小，如-8次方)
bool isZero(double x)
{ // 判断浮点数是否为0
    return fabs(x) <= EPS;
}
bool count24(double a[], int n)
{ // 数组a中n个数能否算出24
    if (n == 1)
    { // 数组中仅有一个元素
        if (isZero(a[0] - 24))
            return true;
        else
            return false;
    }
    double b[5];
    for (int i = 0; i < n - 1; i++)
    { // 枚举两个数的组合
        for (int j = i + 1; j < n; j++)
        {
            int m = 0;
            for (int k = 0; k < n; k++)
            { // 将剩下的n-2个数存放到数组b中
                if (k != i && k != j)
                    b[m++] = a[k];
            }
            b[m] = a[i] + a[j]; // 元素b[m]是a[i]和a[j]相加
            if (count24(b, m + 1))
                return true;
            b[m] = a[i] - a[j]; // 元素b[m]是a[i]和a[j]相减
            if (count24(b, m + 1))
                return true;
            b[m] = a[j] - a[i];
            if (count24(b, m + 1))
                return true;
            b[m] = a[i] * a[j]; // 元素b[m]是a[i]和a[j]相乘
            if (count24(b, m + 1))
                return true;
            if (!isZero(a[j]))
            { // 元素b[m]是a[i]和a[j]相除
                b[m] = a[i] / a[j];
                if (count24(b, m + 1))
                    return true;
            }
            if (!isZero(a[i]))
            {
                b[m] = a[j] / a[i];
                if (count24(b, m + 1))
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    while (true)
    {
        for (int i = 0; i < 4; i++) // 输入4个元素
            cin >> a[i];
        if (isZero(a[0]) && isZero(a[1]) && isZero(a[2]) && isZero(a[3]))
            break;
        if (count24(a, 4)) // 可以算出24
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}