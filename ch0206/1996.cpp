#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int n;
int height[MAXN];
int up[MAXN]; // up[i]表示以第i个点为结尾的最长上升子序列长度
int down[MAXN]; // down[i]表示从第i个点开始的最长下降子序列长度

int solve()
{
    // 初始化：每个点自己都是长度为1的序列
    for(int i = 1; i <= n; i++)
    {
        up[i] = down[i] = 1;
    }

    // 计算up数组：以i结尾的最长上升序列
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(height[i] > height[j])
            {
                up[i] = max(up[i], up[j] + 1);
            }
        }
    }

    // 计算down数组：从i开始的最长下降序列（从后往前算）
    for(int i = n - 1; i >= 1; i--)
    {
        for(int j = n; j > i; j--)
        {
            if(height[i] > height[j])
            {
                down[i] = max(down[i], down[j] + 1);
            }
        }
    }

    // 枚举每个点作为山顶，找出最大值
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        // up[i]和down[i]都包含了点i自己，所以要减1
        
        ans = max(ans, up[i] + down[i] - 1);
    }

    return ans;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> height[i];
    }
    cout << solve() << endl;
    return 0;
}