#include <iostream>
using namespace std;

const int MAXN = 1005;
int n;
int a[MAXN];    // 原始序列
int dp[MAXN];   // dp[i]表示以a[i]结尾的最长上升子序列长度

int solve() {
    // 初始化dp数组，每个元素自己可以构成长度为1的上升子序列
    for(int i = 1; i <= n; i++) {
        dp[i] = 1;
    }
    
    // 对于每个位置i，检查前面的所有位置j
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            // 如果a[i]大于a[j]，可以将a[i]接在以a[j]结尾的上升子序列后面
            if(a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    // 找出dp数组中的最大值
    int ans = dp[1];
    for(int i = 2; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    
    return ans;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    cout << solve() << endl;
    return 0;
}