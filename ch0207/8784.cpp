#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// 计算最大公约数
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// 计算最小公倍数
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int x0, y0;
    cin >> x0 >> y0;

    // 检查y0是否是x0的倍数，如果不是，则没有解
    if(y0 % x0 != 0)
    {
        cout << 0 << endl;
        return 0;
    }

    int count = 0;
    int n = y0 / x0; // n = lcm(p,q) / gcd(p,q)

    // 找出n的所有因子对
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            int j = n / i;
            // 检查i和j是否互质
            if(gcd(i, j) == 1)
            {
                // 如果i和j互质，那么p = x0 * i, q = x0 * j满足条件
                // 同样，p = x0 * j, q = x0 * i也满足条件
                if(i == j)
                {
                    count += 1; // 如果i=j，只有一种情况
                }
                else
                {
                    count += 2; // 否则有两种情况
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}