/*
题目：花生采摘问题
难度：简单到中等
算法：动态规划（路径DP）

思路：
1. 只能向右或向下移动的网格路径问题
2. 每个格子记录到达该点时能获得的最大花生数
3. 每个点的最优值来自上方或左方的最优值加上当前格子的花生数
4. 最终答案在右下角

关键点：
- 状态定义：dp[i][j] 表示到达(i,j)位置时能获得的最大花生数
- 状态转移：dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + field[i][j]
- 边界条件：第一行和第一列需要特殊处理

时间复杂度：O(N*M)
空间复杂度：O(N*M)
*/

#include <iostream>
using namespace std;

const int MAXN = 101;
int field[MAXN][MAXN]; // 存储花生数量
int dp[MAXN][MAXN];    // 存储最大收获数

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int R, C;
        cin >> R >> C;

        // 读入花生数量
        for(int i = 1; i <= R; i++)
        {
            for(int j = 1; j <= C; j++)
            {
                cin >> field[i][j];
            }
        }

        // 初始化dp[1][1]
        dp[1][1] = field[1][1];

        // 处理第一行
        for(int j = 2; j <= C; j++)
        {
            dp[1][j] = dp[1][j-1] + field[1][j];
        }

        // 处理第一列
        for(int i = 2; i <= R; i++)
        {
            dp[i][1] = dp[i-1][1] + field[i][1];
        }

        // 动态规划
        for(int i = 2; i <= R; i++)
        {
            for(int j = 2; j <= C; j++)
            {
                // 从上方或左方选择最大值，再加上当前格子的花生数
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + field[i][j];
            }
        }

        // 输出结果
        cout << dp[R][C] << endl;
    }
    return 0;
}