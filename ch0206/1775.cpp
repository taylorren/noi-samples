#include <bits/stdc++.h>
using namespace std;

const int MAXT = 1005; // 最大时间
const int MAXM = 105;  // 最大草药数

int T, M;        // T:总时间, M:草药数量
int cost[MAXM];  // 采每种草药的时间
int value[MAXM]; // 每种草药的价值
int dp[MAXT];    // dp[i]表示时间为i时能获得的最大价值

void solve()
{
    // 请在这里补充代码，实现：
    // 1. dp数组的初始化
    for(int i = 0; i <= T; i++)
    {
        dp[i] = 0;
    }
    // 2. 对每种草药的处理
    for(int type=1;type<=M;type++)
    {
        for(int i = T; i >=cost[type];i--)
        {
            dp[i] = max(dp[i], dp[i - cost[type]] + value[type]);
        }
    }
    // 3. 状态转移方程的实现
}

int main()
{
    cin >> T >> M;
    for(int i = 1; i <= M; i++)
    {
        cin >> cost[i] >> value[i];
    }

    solve();
    cout << dp[T] << endl;

    return 0;
}