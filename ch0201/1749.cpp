#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int maxSum = 0;

    // 遍历所有可能的组合
    for (int a1 = 0; a1 <= n; a1++)
    {
        for (int a2 = 0; a2 <= n; a2++)
        {
            // 先检查 a1 + a2 是否为 2 的倍数
            if ((a1 + a2) % 2 != 0)
                continue;

            for (int a3 = 0; a3 <= n; a3++)
            {
                // 检查所有条件
                if ((a2 + a3) % 3 == 0 &&
                    (a1 + a2 + a3) % 5 == 0)
                {
                    int sum = a1 + a2 + a3;
                    if (sum > maxSum)
                    {
                        maxSum = sum;
                    }
                }
            }
        }
    }

    cout << maxSum << endl;
    return 0;
}
