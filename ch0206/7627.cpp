#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    const int MAX_N = 100;
    const int MAX_M = 10;

    // dp[i][j] 表示在 i 层楼和 j 个鸡蛋情况下的最坏情况下的最小扔蛋次数
    vector<vector<int>> dp(MAX_N + 1, vector<int>(MAX_M + 1, 0));

    // 初始化 dp 数组
    for(int i = 1; i <= MAX_N; ++i)
    {
        dp[i][1] = i; // 只有一个鸡蛋的情况
    }

    for(int j = 1; j <= MAX_M; ++j)
    {
        dp[0][j] = 0; // 0 层楼的情况
    }

    // 动态规划填表
    for(int i = 1; i <= MAX_N; ++i)
    {
        for(int j = 2; j <= MAX_M; ++j)
        {
            dp[i][j] = INT_MAX;
            for(int k = 1; k <= i; ++k)
            {
                int worst_case = 1 + max(dp[k - 1][j - 1], dp[i - k][j]);
                dp[i][j] = min(dp[i][j], worst_case);
            }
        }
    }

    // 读取输入并输出结果
    while(cin >> n >> m)
    {
        cout << dp[n][m] << endl;
    }

    return 0;
}