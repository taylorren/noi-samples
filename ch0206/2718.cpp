#include <iostream>
using namespace std;

const int MAXN = 21;
long long dp[MAXN][MAXN];  // 使用long long避免溢出

int main() {
    int m, n;
    cin >> m >> n;
    
    // 初始化第一行和第一列
    for(int i = 1; i <= m; i++) {
        dp[i][1] = 1;  // 第一列
    }
    for(int j = 1; j <= n; j++) {
        dp[1][j] = 1;  // 底行
    }
    
    // 动态规划填充数组
    // 从下到上，从左到右填充
    for(int i = 2; i <= m; i++) {
        for(int j = 2; j <= n; j++) {
            // 当前位置的路径数等于下方和左方的路径数之和
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    // 输出结果
    cout << dp[m][n] << endl;
    
    return 0;
}