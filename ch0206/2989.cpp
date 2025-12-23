/*
题目：糖果选择问题
难度：中等
算法：动态规划（背包DP + 余数处理）

思路：
1. 每个糖果可以选或不选，需要找到和为K的倍数的最大值
2. 使用两个DP数组：一个记录余数是否可达，一个记录达到该余数时的最大和
3. 状态转移时需要考虑选和不选两种情况
4. 特别注意要求和大于0且为K的倍数

关键点：
- 状态定义：dp[i][j]表示前i个数能否得到余数j
          sum[i][j]表示前i个数得到余数j时的最大和
- 状态转移：每个数可选可不选
- 结果判断：检查sum[N][0]是否大于0

时间复杂度：O(N*K)
空间复杂度：O(N*K)
*/

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 101;
const int MAXK = 101;
int candies[MAXN];     // 每件产品的糖果数
bool dp[MAXN][MAXK];   // dp[i][j]表示前i个产品能否凑出余数为j的和
int sum[MAXN][MAXK];   // sum[i][j]表示前i个产品凑出余数为j时的最大和

int main() {
    int N, K;
    cin >> N >> K;
    
    // 读入每件产品的糖果数
    for(int i = 1; i <= N; i++) {
        cin >> candies[i];
    }
    
    // 初始化：空集的和为0
    memset(dp, false, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    dp[0][0] = true;
    
    // 动态规划主循环
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < K; j++) {
            // 不选第i个产品的情况
            if(dp[i-1][j]) {
                dp[i][j] = true;
                sum[i][j] = max(sum[i][j], sum[i-1][j]);
            }
            
            // 选第i个产品的情况
            if(dp[i-1][j]) {
                int newMod = (j + candies[i]) % K;
                dp[i][newMod] = true;
                sum[i][newMod] = max(sum[i][newMod], sum[i-1][j] + candies[i]);
            }
        }
    }
    
    // 判断是否存在大于0且为K的倍数的和
    if(dp[N][0] && sum[N][0] > 0) {
        cout << sum[N][0] << endl;
    } else {
        cout << 0 << endl;
    }
    
    return 0;
}