#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T; // 输入组数
    while(T--)
    {
        int N;
        cin >> N; // 输入店铺数量
        vector<int> cash(N);
        for(int i = 0; i < N; ++i)
        {
            cin >> cash[i]; // 输入每家店铺的现金
        }

        if(N == 1)
        {
            cout << cash[0] << endl; // 只有一间店铺
            continue;
        }

        // dp 数组
        vector<int> dp(N);
        dp[0] = cash[0];               // 第一间店铺
        dp[1] = max(cash[0], cash[1]); // 前两间店铺的最大现金

        // 动态规划填表
        for(int i = 2; i < N; ++i)
        {
            dp[i] = max(dp[i - 1], cash[i] + dp[i - 2]);
        }

        // 输出结果
        cout << dp[N - 1] << endl; // 最后一个店铺的最大现金
    }

    return 0;
}