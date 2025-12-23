#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // 枚举总户数
    for(int m = 1;; m++)
    {
        // 计算1到m的和
        int sum = (1 + m) * m / 2;

        // 枚举门牌号
        for(int x = 1; x <= m; x++)
        {
            if(sum - 2 * x == n)
            {
                cout << x << " " << m << endl;
                return 0;
            }
        }
    }

    return 0;
}