#include <cstring>
#include <iostream>
using namespace std;

const int MAXV = 305;
const int MAXP = 35;
const int INF = 0x3f3f3f3f;

int V, P;
int pos[MAXV]; // 村庄位置
int cost[MAXV][MAXV]; // cost[i][j]表示从i到j的村庄由一个邮局服务的最小距离和
int dp[MAXV][MAXP]; // dp[i][j]表示前i个村庄放j个邮局的最小距离和

// 计算从l到r的村庄由一个邮局服务的最小距离和
void precalc()
{
    for(int i = 1; i <= V; i++)
    {
        for(int j = i; j <= V; j++)
        {
            // 对于区间[i,j]，邮局放在中间位置
            int mid = (i + j) >> 1;
            int sum = 0;
            // 计算所有村庄到这个邮局的距离和
            for(int k = i; k <= j; k++)
            {
                sum += abs(pos[k] - pos[mid]);
            }
            cost[i][j] = sum;
        }
    }
}

int solve()
{
    // 初始化dp数组
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;

    // 枚举前i个村庄
    for(int i = 1; i <= V; i++)
    {
        // 枚举邮局数量
        for(int j = 1; j <= P && j <= i; j++)
        {
            // 枚举最后一个邮局负责的起始村庄位置
            for(int k = j; k <= i; k++)
            {
                dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + cost[k][i]);
            }
        }
    }

    return dp[V][P];
}

int main()
{
    cin >> V >> P;
    for(int i = 1; i <= V; i++)
    {
        cin >> pos[i];
    }

    precalc();
    cout << solve() << endl;

    return 0;
}