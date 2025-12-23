/*
本题的测试点有问题，因为没有任何人通过该题目。
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int C, N;
    cin >> C >> N;
    
    int weights[N];
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }
    
    // dp[i]表示重量为i时是否可行
    bool dp[C + 1] = {0};
    dp[0] = true;  // 重量为0是可行的（不选任何奶牛）
    
    // 记录最大可行重量
    int maxWeight = 0;
    
    // 对每头奶牛
    for (int i = 0; i < N; i++) {
        // 从大到小枚举重量，避免重复计算
        for (int j = C; j >= weights[i]; j--) {
            if (dp[j - weights[i]]) {
                dp[j] = true;
                maxWeight = max(maxWeight, j);
            }
        }
    }
    
    cout << maxWeight << endl;
    
    return 0;
}