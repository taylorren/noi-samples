#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 1005; // 最大精灵球数量
const int MAXM = 505;  // 最大体力值

int N, M, K;           // 精灵球数量，初始体力值，小精灵数量
int dp[2][MAXN][MAXM]; // 使用滚动数组，只需要两个状态

void solve()
{
    memset(dp, -1, sizeof(dp));
    dp[0][0][M] = 0; // 初始状态

    int curr = 0; // 当前状态
    int next = 1; // 下一状态

    // 对每个小精灵
    for(int i = 0; i < K; i++)
    {
        int ball, damage;
        cin >> ball >> damage;

        // 清空下一个状态数组
        memset(dp[next], -1, sizeof(dp[next]));

        // 对每种可能的精灵球使用数量
        for(int j = 0; j <= N; j++)
        {
            // 对每种可能的剩余体力值
            for(int k = 0; k <= M; k++)
            {
                if(dp[curr][j][k] == -1)
                    continue;

                // 不收服当前小精灵
                dp[next][j][k] = max(dp[next][j][k], dp[curr][j][k]);

                // 尝试收服当前小精灵
                if(j + ball <= N && k >= damage)
                {
                    dp[next][j + ball][k - damage] =
                        max(dp[next][j + ball][k - damage], dp[curr][j][k] + 1);
                }
            }
        }

        // 交换当前状态和下一状态
        swap(curr, next);
    }

    // 找出最优解
    int maxCount = 0;
    int maxLife = 0;

    for(int j = 0; j <= N; j++)
    {
        for(int k = 0; k <= M; k++)
        {
            if(dp[curr][j][k] > maxCount)
            {
                maxCount = dp[curr][j][k];
                maxLife = k;
            }
            else if(dp[curr][j][k] == maxCount && k > maxLife)
            {
                maxLife = k;
            }
        }
    }

    cout << maxCount << " " << maxLife << endl;
}

int main()
{
    cin >> N >> M >> K;
    solve();
    return 0;
}