#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;
int dp[MAXN][MAXN]; // dp[i][j]表示第一个串前i个字符和第二个串前j个字符的LCS长度
string s1, s2;

int solve()
{
    int len1 = s1.length();
    int len2 = s2.length();

    // 初始化dp数组
    memset(dp, 0, sizeof(dp));

    // 动态规划过程
    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[len1][len2];
}

int main()
{
    while(cin >> s1 >> s2)
    {
        cout << solve() << endl;
    }
    return 0;
}