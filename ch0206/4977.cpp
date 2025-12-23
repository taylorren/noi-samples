#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 105;
int h[MAXN];    // 建筑高度
int dp1[MAXN];  // 从位置i开始向左滑行能经过的最多建筑数
int dp2[MAXN];  // 从位置i开始向右滑行能经过的最多建筑数

// 计算最长递减子序列长度
void solve(int n)
{
    // 初始化dp数组
    for(int i = 0; i < n; i++)
    {
        dp1[i] = dp2[i] = 1;
    }

    // 计算向左滑行的最长递减子序列
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(h[i] < h[j])
            {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }

    // 计算向右滑行的最长递减子序列
    for(int i = n - 2; i >= 0; i--)
    {
        for(int j = n - 1; j > i; j--)
        {
            if(h[i] < h[j])
            {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

    // 找出最大值
    int maxLen = 0;
    for(int i = 0; i < n; i++)
    {
        maxLen = max(maxLen, max(dp1[i], dp2[i]));
    }
    cout << maxLen << endl;
}

int main()
{
    int k;
    cin >> k;
    while(k--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        solve(n);
    }
    return 0;
}