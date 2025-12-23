#include <iostream>
using namespace std;

int dp[51][51];

void init()
{
    // 初始化基础情况
    for(int i = 0; i <= 50; i++) {
        for(int j = 0; j <= 50; j++) {
            dp[i][j] = 0;
        }
    }
    
    // 空集的划分数为1
    for(int j = 1; j <= 50; j++) {
        dp[0][j] = 1;
    }
    
    for(int i = 1; i <= 50; i++)
    {
        for(int j = 1; j <= 50; j++)
        {
            // 不使用j的情况
            if(j > 1) dp[i][j] = dp[i][j-1];
            // 使用j的情况
            if(i >= j) dp[i][j] += dp[i-j][j];
        }
    }
}

int main()
{
    int n;
    init();
    while(cin >> n)
    {
        cout << dp[n][n] << endl;
    }
    return 0;
}