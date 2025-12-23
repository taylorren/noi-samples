#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 1005;
int a[MAXN];  // 原始序列
int dp[MAXN]; // dp[i]表示以第i个数结尾的最大上升子序列和

int main()
{
    int n;
    cin >> n;

    // 读入序列
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = a[i]; // 初始化dp数组，至少包含自身
    }

    // 动态规划过程
    int maxSum = dp[1];
    for(int i = 2; i <= n; i++)
    {
        // 对于每个位置i，查看之前所有小于a[i]的元素
        for(int j = 1; j < i; j++)
        {
            if(a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        maxSum = max(maxSum, dp[i]);
    }

    cout << maxSum << endl;
    return 0;
}