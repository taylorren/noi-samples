/*
算法：贪心算法 + 数学方法
难度：★★★★★ (5星)
描述：装箱问题（不同大小的正方形物品装入正方形箱子）
算法分析：
1. 贪心策略：从大到小处理，先放大的正方形
2. 数学推导：
   - 预计算3×3箱子的剩余空间
   - 计算每种大小正方形的最优放置方式
3. 难点：
   - 需要仔细处理剩余空间的利用
   - 涉及复杂的数学计算和取整
4. 时间复杂度：O(1)，因为只处理固定大小的输入
*/

#include <bits/stdc++.h>
using namespace std;

// 3×3箱子剩余可放2×2的数量映射
const int remainingSpace[4] = {0, 5, 3, 1};

// 计算最少需要的箱子数
int calculateMinBoxes(int boxes[])
{
    int count = 0;

    // 1. 处理大箱子 (6×6, 5×5, 4×4, 3×3)
    count += boxes[5];             // 6×6
    count += boxes[4];             // 5×5
    count += boxes[3];             // 4×4
    count += ceil(boxes[2] / 4.0); // 3×3，每4个一箱

    // 2. 计算可用的2×2空间
    int space2x2 = 5 * boxes[3] +                // 4×4留下的空间
                   remainingSpace[boxes[2] % 4]; // 3×3留下的空间

    // 3. 处理2×2箱子
    if (boxes[1] > space2x2)
    {
        count += ceil((boxes[1] - space2x2) / 9.0); // 新箱子，每箱最多9个2×2
    }

    // 4. 计算可用的1×1空间
    int space1x1 = 36 * count -    // 总空间
                   36 * boxes[5] - // 6×6占用
                   25 * boxes[4] - // 5×5占用
                   16 * boxes[3] - // 4×4占用
                   9 * boxes[2] -  // 3×3占用
                   4 * boxes[1];   // 2×2占用

    // 5. 处理1×1箱子
    if (boxes[0] > space1x1)
    {
        count += ceil((boxes[0] - space1x1) / 36.0); // 新箱子，每箱最多36个1×1
    }

    return count;
}

// 检查是否全为0
bool isAllZero(int boxes[])
{
    for (int i = 0; i < 6; i++)
    {
        if (boxes[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    int boxes[6]; // 从boxes[0]到boxes[5]对应1×1到6×6的箱子

    while (true)
    {
        // 读入六种箱子的数量
        for (int i = 0; i < 6; i++)
        {
            cin >> boxes[i];
        }

        // 检查是否结束
        if (isAllZero(boxes))
            break;

        // 计算并输出结果
        cout << calculateMinBoxes(boxes) << endl;
    }

    return 0;
}