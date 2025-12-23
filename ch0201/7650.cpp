#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int count = 0;
    // 遍历所有可能的x值
    for (int x = 0; x <= c / a; x++)
    {
        // 对于每个x，计算对应的y
        if ((c - a * x) % b == 0)
        {
            int y = (c - a * x) / b;
            // 如果y是非负数，则找到一组解
            if (y >= 0)
            {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}