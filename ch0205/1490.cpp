#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 骑士周游问题
 * 题目要求：在p*q的棋盘上找到一条访问所有格子的骑士路径
 * 核心算法：DFS + 回溯 + 字典序优化
 * 1. p表示行数（数字1..p），q表示列数（字母A..）
 * 2. 每一步都选择字典序最小的下一步移动
 * 3. 如果当前路径不可行，回溯并尝试下一个选择
 */

struct Move
{
    int x, y;
    string pos;  // 位置的字符串表示
    
    bool operator<(const Move& other) const
    {
        return pos < other.pos;
    }
};

// 骑士的8种移动方式
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

// 检查位置是否在棋盘内
bool inBound(int x, int y, int p, int q)
{
    return x >= 0 && x < p && y >= 0 && y < q;
}

// 将位置转换为棋盘表示法（如A1, B2等）
string posToString(int x, int y)
{
    string res;
    res += (char)('A' + y);
    res += (char)('1' + x);
    return res;
}

// 获取所有可能的下一步移动，并按字典序排序
vector<Move> getNextMoves(int x, int y, int p, int q, 
    const vector<vector<bool>>& visited)
{
    vector<Move> moves;
    for(int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(inBound(nx, ny, p, q) && !visited[nx][ny])
        {
            moves.push_back({nx, ny, posToString(nx, ny)});
        }
    }
    sort(moves.begin(), moves.end());
    return moves;
}

// DFS搜索路径
bool dfs(int x, int y, int step, int p, int q, vector<vector<bool>>& visited,
    string& path, int total)
{
    visited[x][y] = true;
    path += posToString(x, y);
    
    if(step == total)
    {
        return true;
    }
    
    // 获取所有可能的下一步移动，并按字典序排序
    vector<Move> nextMoves = getNextMoves(x, y, p, q, visited);
    
    // 按字典序尝试每一个可能的移动
    for(const Move& move : nextMoves)
    {
        if(dfs(move.x, move.y, step + 1, p, q, visited, path, total))
        {
            return true;
        }
    }
    
    visited[x][y] = false;
    path = path.substr(0, path.length() - 2);
    return false;
}

// 寻找字典序最小的路径
string findPath(int p, int q)
{
    if(p * q > 26 || p * q <= 0)
    {
        return "impossible";
    }
    
    // 生成所有可能的起点，并按字典序排序
    vector<Move> startPoints;
    for(int y = 0; y < q; y++)
    {
        for(int x = 0; x < p; x++)
        {
            startPoints.push_back({x, y, posToString(x, y)});
        }
    }
    sort(startPoints.begin(), startPoints.end());
    
    // 从字典序最小的起点开始尝试
    for(const Move& start : startPoints)
    {
        string path;
        vector<vector<bool>> visited(p, vector<bool>(q, false));
        if(dfs(start.x, start.y, 1, p, q, visited, path, p * q))
        {
            return path;
        }
    }
    
    return "impossible";
}

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        int p, q;
        cin >> p >> q;
        
        cout << "Scenario #" << i << ":" << endl;
        cout << findPath(p, q) << endl << endl;
    }
    
    return 0;
}