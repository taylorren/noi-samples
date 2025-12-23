#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 205;
const int MAXM = 10005;
bool dp[MAXN][MAXM]; // dp[i][j]表示使用前i个硬币能否凑出j
bool must[MAXN];     // must[i]表示第i个硬币是否必须使用
int coins[MAXN];     // 存储硬币面值
int n, x;

// 检查不使用第k个硬币是否能凑出目标金额
bool checkWithout(int k)
{
    // dp[i][j]表示不使用第k个硬币，使用前i个硬币能否凑出j
    bool dp2[MAXM] = {0};
    dp2[0] = true;

    for(int i = 0; i < n; i++)
    {
        if(i == k)
            continue; // 跳过第k个硬币
        for(int j = x; j >= coins[i]; j--)
        {
            dp2[j] |= dp2[j - coins[i]];
        }
    }
    return dp2[x];
}

int main()
{
    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    // 检查每个硬币
    vector<int> result;
    for(int i = 0; i < n; i++)
    {
        if(!checkWithout(i))
        {
            result.push_back(coins[i]);
        }
    }

    // 输出结果
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}