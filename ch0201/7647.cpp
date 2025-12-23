#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    // 从2开始枚举，直到找到满足条件的最小值
    for(int x = 2;; x++)
    {
        if(a % x == b % x && b % x == c % x)
        {
            cout << x << endl;
            break;
        }
    }

    return 0;
}