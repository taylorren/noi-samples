#include <iostream>
using namespace std;

const int MAXN = 21;
const int MAXT = 1001;
int nums[MAXN]; // 存储输入的数字
int dp[MAXT];   // dp[j]表示和为j的组合数目

int main()
{
    int n, t;
    cin >> n >> t;

    // 读入n个数
    for(int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    // 初始化：空集的和为0，只有一种方案
    dp[0] = 1;

    // 动态规划部分：
    // 对于每个数nums[i]，更新所有可能的和
    // 从后往前遍历j，避免重复使用同一个数字
    for(int i = 1; i <= n; i++)
    {
        for(int j = t; j >= nums[i]; j--)
        {
            dp[j] += dp[j - nums[i]];
        }
    }

    // 输出结果
    cout << dp[t] << endl;

    return 0;
}