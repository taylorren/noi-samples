#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 15;
char wall[MAX_N][MAX_N];    // 原始墙的状态
bool current[MAX_N][MAX_N]; // 当前状态 (true表示白色)
bool painted[MAX_N][MAX_N]; // 是否涂画
int n;

// 改变一块砖及其相邻砖的颜色
void paint(int row, int col) {
    // 改变当前位置
    current[row][col] = !current[row][col];
    
    // 改变上方砖
    if (row > 0)
        current[row-1][col] = !current[row-1][col];
    
    // 改变下方砖
    if (row < n-1)
        current[row+1][col] = !current[row+1][col];
    
    // 改变左边砖
    if (col > 0)
        current[row][col-1] = !current[row][col-1];
    
    // 改变右边砖
    if (col < n-1)
        current[row][col+1] = !current[row][col+1];
}

// 检查是否所有砖都是黄色
bool allYellow() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (current[i][j]) // true表示白色
                return false;
    return true;
}

// 计算涂画的砖数
int countPainted() {
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (painted[i][j])
                count++;
    return count;
}

int main() {
    // 读入数据
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> wall[i][j];
        }
    }
    
    int minPaint = INT_MAX;
    
    // 枚举第一行的所有可能状态
    for (int state = 0; state < (1 << n); state++) {
        // 重置当前状态
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                current[i][j] = (wall[i][j] == 'w');
                painted[i][j] = false;
            }
        }
        
        // 设置第一行的涂画状态
        for (int j = 0; j < n; j++) {
            if (state & (1 << j)) {
                painted[0][j] = true;
                paint(0, j);
            }
        }
        
        // 根据每一行的状态决定下一行的涂画
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (current[i-1][j]) {  // 如果上一行是白色
                    painted[i][j] = true;
                    paint(i, j);
                }
            }
        }
        
        if (allYellow()) {
            minPaint = min(minPaint, countPainted());
        }
    }
    
    if (minPaint == INT_MAX) {
        cout << "inf" << endl;
    } else {
        cout << minPaint << endl;
    }
    
    return 0;
}
