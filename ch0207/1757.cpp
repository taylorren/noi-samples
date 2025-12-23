// #include <iostream>
// using namespace std;

// int n;
// int a[25];
// int ans = 0;

// void dfs(int pos, int sum) {
//     if (sum == 40) {
//         ans++;
//         return;
//     }
//     if (sum > 40 || pos >= n) {
//         return;
//     }
    
//     // 选择当前物品
//     dfs(pos + 1, sum + a[pos]);
//     // 不选择当前物品
//     dfs(pos + 1, sum);
// }

// int main() {
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
    
//     dfs(0, 0);
//     cout << ans << endl;
    
//     return 0;
// }

#include <iostream>
using namespace std;

int n;
int a[25];
long long dp[25][41];  // 使用long long避免溢出

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // 初始化：空集的和为0，方案数为1
    dp[0][0] = 1;
    
    // 对每个物品
    for (int i = 0; i < n; i++) {
        // 对每个可能的体积
        for (int j = 0; j <= 40; j++) {
            // 不选择当前物品
            dp[i + 1][j] += dp[i][j];
            // 选择当前物品（如果总体积不超过40）
            if (j + a[i] <= 40) {
                dp[i + 1][j + a[i]] += dp[i][j];
            }
        }
    }
    
    cout << dp[n][40] << endl;
    return 0;
}