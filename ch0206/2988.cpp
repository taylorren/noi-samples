/*
题目：编辑距离问题
难度：中等
算法：动态规划（字符串DP）

思路：
1. 将一个字符串变成另一个字符串，可以修改或删除字符
2. dp[i][j]表示将s1的前i个字符变成s2的前j个字符所需的最小操作数
3. 如果当前字符相同，不需要操作；否则可以选择修改或删除
4. 最终答案在dp[n][m]，其中n和m是两个字符串的长度

关键点：
- 状态定义：dp[i][j] 表示s1前i个字符到s2前j个字符的最小操作数
- 状态转移：
  * 如果s1[i] == s2[j]：dp[i][j] = dp[i-1][j-1]
  * 否则：dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1
- 边界条件：需要初始化第一行和第一列

时间复杂度：O(N*M)
空间复杂度：O(N*M)
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 1001;
int dp[MAXN][MAXN];  // dp[i][j]表示s1前i个字符变成s2前j个字符的最小操作数

int editDistance(string s1, string s2)
{
    int len1 = s1.length();
    int len2 = s2.length();

    // 初始化边界条件
    // 一个空串变成另一个串需要的操作数就是另一个串的长度
    for(int i = 0; i <= len1; i++)
        dp[i][0] = i;  // 全部删除
    for(int j = 0; j <= len2; j++)
        dp[0][j] = j;  // 全部添加

    // 动态规划
    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                // 当前字符相同，不需要操作
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                // 当前字符不同，取三种操作中的最小值：
                // 1. 修改当前字符：dp[i-1][j-1] + 1
                // 2. 删除s1当前字符：dp[i-1][j] + 1
                // 3. 删除s2当前字符：dp[i][j-1] + 1
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }

    return dp[len1][len2];
}

int main()
{
    int n;
    cin >> n;
    string s1, s2;

    while(n--)
    {
        cin >> s1 >> s2;
        cout << editDistance(s1, s2) << endl;
    }

    return 0;
}
