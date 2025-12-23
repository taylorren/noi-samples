/*
算法：贪心算法（类似田忌赛马）
难度：★★★☆☆ (3星)
描述：巧克力卡牌游戏，每轮比较双方的牌大小决定得分
算法分析：
1. 贪心策略：
   - 最大得分：优先用大牌赢对方大牌，不行则用小牌输对方大牌
   - 最小得分：利用每局总分为4的特性
2. 使用双指针处理排序后的数组
3. 时间复杂度：O(NlogN)
*/

#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int n;

// 求一方的最大得分
int solve(int computer[1005], int player[1005]) {
    int ans = 0;
    int computer_left = 1, computer_right = n;  // computer的左右指针
    int player_left = 1, player_right = n;  // player的左右指针
    
    while(player_left <= player_right) {
        if(player[player_right] > computer[computer_right]) {  // player的最大牌能赢computer的最大牌
            player_right--; computer_right--;
            ans += 3;
        }
        else if(player[player_right] < computer[computer_right]) {  // player的最大牌输给computer的最大牌
            player_left++; computer_right--;
            ans += 1;
        }
        else {  // player的最大牌等于computer的最大牌
            if(player[player_left] > computer[computer_left]) {  // 看player的最小牌能否赢computer的最小牌
                player_left++; computer_left++;
                ans += 3;
            }
            else {  // player的最小牌不能赢computer的最小牌
                if(player[player_left] < computer[computer_right]) {  // 用player的最小牌去输computer的最大牌
                    player_left++; computer_right--;
                    ans += 1;
                }
                else {  // 平局
                    player_left++; computer_right--;
                    ans += 2;
                }
            }
        }
    }
    return ans;
}

int main() {
    while(cin >> n, n) {
        int computer[1005], player[1005];
        memset(computer, 0, sizeof(computer));
        memset(player, 0, sizeof(player));
        
        for(int i = 1; i <= n; ++i)
            cin >> computer[i];  // computer的卡牌
        for(int i = 1; i <= n; ++i)
            cin >> player[i];  // player的卡牌
            
        sort(computer + 1, computer + 1 + n);  // 排序
        sort(player + 1, player + 1 + n);
        
        int max_score = solve(computer, player);  // player的最大得分
        cout << max_score << " " << 4 * n - solve(player, computer) << endl;  // player的最大得分和最小得分
    }
    return 0;
}