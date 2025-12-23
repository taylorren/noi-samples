/*
算法：数学方法
难度：★☆☆☆☆ (1星)
描述：教会遗产分配问题，为N个亲属分配递增的份额
算法分析：
1. 关键发现：给每个亲属分配N+i的份额即可满足要求
2. 无需复杂的算法，直接构造解
3. 时间复杂度：O(N)
*/

#include <iostream>
#include <vector>

using namespace std;

// 函数：计算最小的教会份额
void findMinChurchShare(int N)
{
    vector<int> x(N); // 存储每个亲属的 x_i 值

    // 从最重要的亲属开始，给他们分配份额
    for (int i = 0; i < N; ++i)
    {
        // 对于第 i 个亲属，设置 x_i 为 N + i
        // 这样可以确保 x_i 是递增的
        x[i] = N + i; // 例如，N=3时，x=[3, 4, 5]
    }

    // 输出最佳的 x_i 值
    for (int i = 0; i < N; ++i)
    {
        cout << x[i] << endl;
    }
}

int main()
{
    int N;    // 亲属的数量
    cin >> N; // 输入亲属数量

    findMinChurchShare(N); // 调用函数计算最小教会份额

    return 0;
}
