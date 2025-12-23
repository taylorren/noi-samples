// DFS搜索
// BFS搜索会超时

#include <iostream>
#include <vector>
using namespace std;

// 9个移动操作影响的时钟
const int moves[9][6] = {
    {0,1,3,4,-1}, // 1: ABDE
    {0,1,2,-1},   // 2: ABC
    {1,2,4,5,-1}, // 3: BCEF
    {0,3,6,-1},   // 4: ADG
    {1,3,4,5,7,-1}, // 5: BDEFH
    {2,5,8,-1},   // 6: CFI
    {3,4,6,7,-1}, // 7: DEGH
    {6,7,8,-1},   // 8: GHI
    {4,5,7,8,-1}  // 9: EFHI
};

int clocks[9];
vector<int> result;
vector<int> current;
int minSteps = 1000000;

// 将时钟转动指定次数
void rotate(const int move[], int times) {
    for (int i = 0; move[i] != -1; i++) {
        clocks[move[i]] = (clocks[move[i]] + times) % 4;
    }
}

// 检查是否所有时钟都指向12点
bool isFinished() {
    for (int i = 0; i < 9; i++) {
        if (clocks[i] != 0) return false;
    }
    return true;
}

// DFS搜索解
void dfs(int moveIndex) {
    // 剪枝：如果当前步数已经超过已知最小步数，直接返回
    if (current.size() >= minSteps) return;
    
    // 如果所有时钟都指向12点，更新结果
    if (isFinished()) {
        if (current.size() < minSteps) {
            minSteps = current.size();
            result = current;
        }
        return;
    }
    
    // 如果已经尝试完所有移动，返回
    if (moveIndex >= 9) return;
    
    // 尝试当前移动0-3次
    for (int times = 0; times <= 3; times++) {
        // 执行移动
        rotate(moves[moveIndex], times);
        
        // 如果选择了这个移动（次数>0），将其添加到序列中
        for (int t = 0; t < times; t++) {
            current.push_back(moveIndex + 1);
        }
        
        // 递归尝试下一个移动
        dfs(moveIndex + 1);
        
        // 回溯：撤销移动
        for (int t = 0; t < times; t++) {
            current.pop_back();
        }
        rotate(moves[moveIndex], (4 - times) % 4);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 读入初始状态
    for (int i = 0; i < 9; i++) {
        cin >> clocks[i];
    }
    
    // 搜索解
    dfs(0);
    
    // 输出结果
    for (size_t i = 0; i < result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;
    
    return 0;
}