#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int m, n, x, s;
    s = 0;

    cin >> m >> n >> x;
    while (x > 0)
    {
        x--;        // 用一个能量块
        s += n;     // 体力增加
        if (s >= m) // 溢出
        {
            s = m;
            while (s)
            {
                if (s % n == 0)
                {
                    n++;
                }
                s--;
            }
        }
    }

    cout << n << endl;

    return 0;
}
