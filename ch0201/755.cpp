
#include <iostream>
#include <queue>
using namespace std;

char board[4][4];
const int dx[] = {-1, 0, 1, 0, 0};
const int dy[] = {0, 1, 0, -1, 0};

bool inBoard(int x, int y) {
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}

// 获取位置(x,y)的状态
bool getState(int state, int x, int y) {
    int pos = x * 4 + y;
    return (state >> pos) & 1;
}

// 翻转位置(x,y)的状态
int flipBit(int state, int x, int y) {
    int pos = x * 4 + y;
    return state ^ (1 << pos);
}

// 翻转一个位置及其相邻的棋子
int flip(int state, int x, int y) {
    for(int i = 0; i < 5; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(inBoard(nx, ny)) {
            state = flipBit(state, nx, ny);
        }
    }
    return state;
}

// 检查是否所有棋子都是同一颜色
bool isAllSame(int state) {
    return state == 0 || state == 0xFFFF;
}

int solve() {
    // 将初始棋盘转换为整数状态
    int start = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(board[i][j] == 'b') {
                start |= (1 << (i * 4 + j));
            }
        }
    }
    
    // 如果初始状态就满足条件
    if(isAllSame(start)) return 0;
    
    // 使用pair来存储状态和步数
    queue<pair<int, int>> q;
    q.push({start, 0});
    
    // 记录已访问的状态
    bool visited[1 << 16] = {false};
    visited[start] = true;
    
    while(!q.empty()) {
        int curr = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        // 尝试翻转每一个位置
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                int next = flip(curr, i, j);
                
                if(isAllSame(next)) return steps + 1;
                
                if(!visited[next] && steps < 10) {
                    visited[next] = true;
                    q.push({next, steps + 1});
                }
            }
        }
    }
    
    return -1;
}

int main() {
    // 读入棋盘
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            cin >> board[i][j];
    
    int result = solve();
    if(result == -1) {
        cout << "Impossible" << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}