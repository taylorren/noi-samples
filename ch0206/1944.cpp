#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;
int n;
int dp[MAXN]; // dp[i]表示还剩i块巧克力时的方案数

// 提示：考虑以下问题
// 1. 如果今天吃1块，还剩多少块？方案数是多少？
// 2. 如果今天吃2块，还剩多少块？方案数是多少？
// 3. 总方案数应该是什么？
int solve()
{
    // 初始化：考虑最基本的情况
    dp[0] = 1; // 0块巧克力只有1种方案（已经吃完了）
    dp[1] = 1; // 1块巧克力只有1种方案（吃掉它）

    // TODO: 请在这里实现dp逻辑
    // 提示：对于i块巧克力，可以第一天吃1块或2块
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{
    cin >> n;
    cout << solve() << endl;
    return 0;
}