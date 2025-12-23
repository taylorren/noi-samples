/*
算法：贪心算法
难度：★★☆☆☆ (2星)
描述：部分背包问题（Fractional Knapsack）
算法分析：
1. 贪心策略：按单位价值排序，优先选择单位价值高的物品
2. 可以取物品的一部分（不同于0/1背包）
3. 时间复杂度：O(NlogN)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// 结构体表示金属的重量和价值
struct Metal
{
    int weight;
    int value;
    double valuePerWeight; // 单位重量的价值
};

// 比较函数，用于排序
bool compare(Metal a, Metal b)
{
    return a.valuePerWeight > b.valuePerWeight; // 按单位价值降序排序
}

int main()
{
    int k; // 测试数据的组数
    cin >> k;

    while (k--)
    {
        int w; // 口袋承重上限
        cin >> w;

        int s; // 金属种类
        cin >> s;

        vector<Metal> metals(s); // 存储金属信息

        // 输入金属的重量和价值
        for (int i = 0; i < s; i++)
        {
            cin >> metals[i].weight >> metals[i].value;
            metals[i].valuePerWeight = 1.0 * metals[i].value / metals[i].weight; // 计算单位价值
        }

        // 按单位价值降序排序
        sort(metals.begin(), metals.end(), compare);

        double totalValue = 0.0; // 总价值
        for (const auto &metal : metals)
        {
            if (w == 0)
                break; // 如果口袋已满，退出循环

            if (metal.weight <= w)
            {
                // 如果当前金属可以完全装入口袋
                totalValue += metal.value; // 加上金属的总价值
                w -= metal.weight;         // 减去口袋的剩余容量
            }
            else
            {
                // 如果当前金属不能完全装入口袋
                totalValue += metal.valuePerWeight * w; // 加上部分价值
                w = 0;                                  // 口袋已满
            }
        }

        // 输出结果，保留两位小数
        cout << fixed << setprecision(2) << totalValue << endl;
    }

    return 0;
}