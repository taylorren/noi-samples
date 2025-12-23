#include <iostream>
using namespace std;

const int MOD = 10000;
const int MAXN = 205;
const int MAXV = 405;

int n;
int a[MAXN];
int dp[MAXV];  // 使用一维DP数组优化空间

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // 初始化：空集的和为0，方案数为1
    dp[0] = 1;
    
    // 对每个物品
    for (int i = 0; i < n; i++) {
        // 从大到小枚举体积，避免重复计算
        for (int j = 400; j >= a[i]; j--) {
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
    }
    
    cout << dp[400] << endl;
    return 0;
}