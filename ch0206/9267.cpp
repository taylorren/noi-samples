#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 函数用于计算安全的放置方案总数
ll count_safe_placements(int N, int M)
{
    // 初始化 dp 数组，dp[i][k] 表示长度为 i，结尾有 k 个连续的 '1' 的方案数
    vector<vector<ll>> dp(N + 1, vector<ll>(M, 0));
    dp[0][0] = 1; // 空字符串只有一种情况，没有连续的 '1'

    // 填充 dp 数组
    for(int i = 1; i <= N; i++)
    {
        // 放 '0'，重置连续 '1' 的数量为 0
        ll sum_prev = 0;
        for(int k = 0; k < M; k++)
        {
            sum_prev += dp[i - 1][k];
        }
        dp[i][0] = sum_prev;

        // 放 '1'，连续 '1' 的数量加一
        for(int k = 1; k < M; k++)
        {
            dp[i][k] = dp[i - 1][k - 1];
        }
    }

    // 计算最终结果，即所有 dp[N][0..M-1] 的总和
    ll S = 0;
    for(int k = 0; k < M; k++)
    {
        S += dp[N][k];
    }
    return S;
}

int main()
{
    int N, M;
    // 读取输入
    cin >> N >> M;
    // 计算并输出结果
    cout << count_safe_placements(N, M) << endl;
    return 0;
}
