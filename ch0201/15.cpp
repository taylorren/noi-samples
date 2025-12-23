#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 存储称重信息
struct Weighing
{
    string left;  // 左边的硬币
    string right; // 右边的硬币
    char result;  // 称重结果 ('u' - up, 'd' - down, 'e' - even)
};

// 判断给定硬币是否是伪造的
bool isCounterfeit(const char coin, int expectedWeight, const vector<Weighing> &weighings)
{
    bool foundInWeighing = false; // 标记硬币是否在称重中出现

    for (const auto &weighing : weighings)
    {
        bool foundInCurrentWeighing = false; // 当前称重中是否找到目标硬币

        // 检查左边的硬币
        for (const char &c : weighing.left)
        {
            if (c == coin)
            {
                foundInCurrentWeighing = true; // 找到目标硬币
                foundInWeighing = true;        // 在至少一次称重中找到目标硬币

                // 如果称重结果是平衡，返回 false
                if (weighing.result == 'e')
                    return false;

                // 确定硬币的实际重量
                int actualWeight = (weighing.result == 'u') ? 1 : 2; // 'u' 表示左边重
                if (actualWeight != expectedWeight)
                    return false; // 与期望重量不符
            }
        }

        // 检查右边的硬币
        for (const char &c : weighing.right)
        {
            if (c == coin)
            {
                foundInCurrentWeighing = true; // 找到目标硬币
                foundInWeighing = true;        // 在至少一次称重中找到目标硬币

                // 如果称重结果是平衡，返回 false
                if (weighing.result == 'e')
                    return false;

                // 确定硬币的实际重量
                int actualWeight = (weighing.result == 'd') ? 1 : 2; // 'd' 表示右边重
                if (actualWeight != expectedWeight)
                    return false; // 与期望重量不符
            }
        }

        // 如果目标硬币未在当前称重中出现且称重结果不是平衡，返回 false
        if (!foundInCurrentWeighing && weighing.result != 'e')
            return false;
    }

    return foundInWeighing; // 返回是否在至少一次称重中找到目标硬币
}

int main()
{
    int testCases;
    cin >> testCases; // 读取案例数量

    while (testCases--)
    {
        vector<Weighing> weighings(3); // 存储三次称重的信息

        // 读取三次称重的信息
        for (int i = 0; i < 3; i++)
        {
            string left, right, result;
            cin >> left >> right >> result;
            weighings[i] = {left, right, result[0]}; // 将结果转换为字符
        }

        // 检查每个硬币是否是伪造的
        for (char coin = 'A'; coin <= 'L'; coin++)
        {
            for (int weight = 1; weight <= 2; weight++)
            { // 1: 重, 2: 轻
                if (isCounterfeit(coin, weight, weighings))
                {
                    cout << coin << " is the counterfeit coin and it is "
                         << (weight == 1 ? "heavy" : "light") << '.' << endl;
                    break; // 找到伪造硬币后跳出循环
                }
            }
        }
    }
    return 0;
}