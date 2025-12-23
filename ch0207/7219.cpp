#include <iostream>
using namespace std;

// dp1[i][j]: 将i划分成j个正整数之和的划分数目
// dp2[i]: 将i划分成若干个不同正整数之和的划分数目
// dp3[i]: 将i划分成若干个奇正整数之和的划分数目
int dp1[51][51], dp2[51], dp3[51];

void init() {
    // 初始化dp1
    dp1[0][0] = 1;
    for(int i = 1; i <= 50; i++) {
        for(int j = 1; j <= i; j++) {
            // 不使用j的情况
            dp1[i][j] = dp1[i-1][j-1];
            // 使用j的情况
            if(i-j >= j) dp1[i][j] += dp1[i-j][j];
        }
    }
    
    // 初始化dp2 - 划分成若干个不同正整数之和
    for(int i = 0; i <= 50; i++) {
        dp2[i] = 0;
    }
    dp2[0] = 1;
    for(int i = 1; i <= 50; i++) {
        for(int j = 50; j >= i; j--) {
            dp2[j] += dp2[j-i];
        }
    }
    
    // 初始化dp3 - 划分成若干个奇正整数之和
    dp3[0] = 1;
    for(int i = 1; i <= 50; i += 2) {  // 只考虑奇数
        for(int j = i; j <= 50; j++) {
            dp3[j] += dp3[j-i];
        }
    }
}

int main() {
    int n, k;
    init();
    
    while(cin >> n >> k) {
        cout << dp1[n][k] << endl;
        cout << dp2[n] << endl;
        cout << dp3[n] << endl;
    }
    
    return 0;
}