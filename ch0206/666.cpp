#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int M, N;
        cin >> M >> N;

        int dp[M + 1][N + 1] = {0}; // 使用二维数组

        // 初始化
        for(int n = 0; n <= N; ++n)
        {
            dp[0][n] = 1; // 没有苹果时只有一种分法
        }

        for(int m = 1; m <= M; ++m)
        {
            for(int n = 1; n <= N; ++n)
            {
                if(m < n)
                {
                    dp[m][n] = dp[m][m]; // 苹果数少于盘子数
                }
                else
                {
                    dp[m][n] = dp[m][n - 1] + dp[m - n][n]; // 根据状态转移方程
                }
            }
        }

        cout << dp[M][N] << endl;
    }
    return 0;
}