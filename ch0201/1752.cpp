#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;

    // 如果总脚数为奇数，或者小于2，则无解
    if (a % 2 == 1 || a < 2)
    {
        cout << "0 0" << endl;
        return 0;
    }

    int min_animals = 0;
    int max_animals = 0;

    // 计算最小动物数
    // 尽量用4只脚的兔子
    int rabbits = a / 4;        // 最多能放多少只兔子
    int remaining_feet = a % 4; // 剩余的脚数
    if (remaining_feet == 0)
    {
        min_animals = rabbits;
    }
    else if (remaining_feet == 2)
    {
        min_animals = rabbits + 1; // 加一只鸡
    }

    // 计算最大动物数
    // 尽量用2只脚的鸡
    max_animals = a / 2; // 如果全是鸡

    // 如果无解（比如最小数为0）
    if (min_animals == 0)
    {
        cout << "0 0" << endl;
    }
    else
    {
        cout << min_animals << " " << max_animals << endl;
    }

    return 0;
}
