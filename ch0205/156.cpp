#include <iostream>
#include <vector>
using namespace std;

/*
 * 字母棋盘最长路径问题
 * 题目要求：在R×C的字母棋盘上，从左上角开始移动
 * 规则：
 * 1. 每次可以向上下左右四个方向移动
 * 2. 不能访问相同的字母两次
 * 目标：找到最长的可行路径
 * 算法：DFS + 回溯 + 字母访问标记
 * 时间复杂度：O(4^(R*C))，实际因为字母限制会小很多
 * 空间复杂度：O(R*C + 26)，棋盘和字母访问标记
 */

// 四个方向的移动：上、下、左、右
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

// 检查位置是否在棋盘内
bool inBound(int x, int y, int r, int c)
{
    return x >= 0 && x < r && y >= 0 && y < c;
}

// DFS搜索最长路径
// x, y: 当前位置
// len: 当前路径长度
// visited: 记录每个字母是否被访问过
int dfs(int x, int y, int r, int c, const vector<vector<char>>& board,
    vector<bool>& visited)
{
    // 记录当前字母已访问
    char letter = board[x][y];
    visited[letter - 'A'] = true;
    
    int maxLen = 1;  // 当前位置算一步
    
    // 尝试四个方向的移动
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // 如果新位置有效且字母未访问过
        if(inBound(nx, ny, r, c) && !visited[board[nx][ny] - 'A'])
        {
            // 递归搜索，更新最大长度
            int len = 1 + dfs(nx, ny, r, c, board, visited);
            maxLen = max(maxLen, len);
        }
    }
    
    // 回溯：撤销当前字母的访问标记
    visited[letter - 'A'] = false;
    return maxLen;
}

int main()
{
    int r, c;
    cin >> r >> c;
    
    // 读入字母棋盘
    vector<vector<char>> board(r, vector<char>(c));
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> board[i][j];
        }
    }
    
    // 字母访问标记数组
    vector<bool> visited(26, false);  // A-Z的访问标记
    
    // 从左上角(0,0)开始搜索
    cout << dfs(0, 0, r, c, board, visited) << endl;
    
    return 0;
}