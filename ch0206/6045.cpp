#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
int n, k;
int m[MAXN], p[MAXN];
int dp[MAXN]; // dp[i]表示考虑到第i个位置时的最大利润

// 检查位置i是否可以与前面已选择的位置j共存
bool isValid(int i, int j)
{
    return m[i] - m[j] > k;
}

int solve()
{
    // 初始化dp数组
    for(int i = 0; i < n; i++)
    {
        dp[i] = p[i]; // 至少可以获得当前位置的利润
    }

    // 对每个位置，尝试与前面的位置组合
    for(int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i], dp[i - 1]); // 不选当前位置
        for(int j = i - 1; j >= 0; j--)
        {
            if(isValid(i, j))
            {
                // 如果位置i和j的距离大于k，可以选择当前位置
                dp[i] = max(dp[i], dp[j] + p[i]);
            }
        }
    }

    return dp[n - 1];
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        // 输入数据
        cin >> n >> k;
        for(int i = 0; i < n; i++)
        {
            cin >> m[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        // 输出结果
        cout << solve() << endl;
    }
    return 0;
}