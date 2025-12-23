/*
题目：正负号序列问题
难度：中等
算法：动态规划（余数状态DP）

思路：
1. 对于每个数，可以选择加上或减去，需要考虑所有可能的组合
2. 使用DP数组记录每个前缀能达到的所有可能的余数
3. 状态转移时需要同时考虑加和减两种情况
4. 特别注意处理负数的余数，使用((x % K + K) % K)确保余数为正

关键点：
- 状态定义：dp[i][j] 表示前i个数能否得到余数j
- 状态转移：对每个数有+/-两种选择
- 结果判断：检查dp[N][0]是否为true

时间复杂度：O(N*K)
空间复杂度：O(N*K)
*/

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 10000;
const int MAXK = 100;
int nums[MAXN];        // 存储输入的数字
bool dp[MAXN][MAXK];   // dp[i][j]表示前i个数能否得到余数j

int main() {
    int N, K;
    cin >> N >> K;
    
    // 读入N个数
    for(int i = 1; i <= N; i++) {
        cin >> nums[i];
    }
    
    // 初始化：只有空集的和为0
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    
    // 动态规划主循环
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < K; j++) {
            if(dp[i-1][j]) {
                // 加上当前数的情况
                int pos_mod = ((j + nums[i]) % K + K) % K;
                dp[i][pos_mod] = true;
                
                // 减去当前数的情况
                int neg_mod = ((j - nums[i]) % K + K) % K;
                dp[i][neg_mod] = true;
            }
        }
    }
    
    // 判断是否存在一种组合使得和能被K整除
    if(dp[N][0]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}