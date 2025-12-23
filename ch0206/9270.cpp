#include <iostream>
#include <vector>
using namespace std;

const int MOD = 2005;

int main()
{
    // 初始化 dp 和子状态数组
    vector<int> dp(1000001);
    // 初始设定值
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 6;
    dp[4] = 9;

    // 状态转移
    int N; 
    cin>>N;
    for(int i = 5; i <= N; ++i)
    {
        dp[i] = (dp[i-1]+dp[i-3]+dp[i-4])%MOD;
    }

    // 处理输入长度L
    cout<<dp[N]<<endl;
    return 0;
}
