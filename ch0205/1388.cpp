
#include <iostream>
#include <vector>
using namespace std;

/*
 * 水坑计数问题
 * 题目要求：在N*M的矩阵中统计连通的水坑('W')数量
 * 核心算法：DFS（深度优先搜索）
 * 1. 遍历矩阵中的每个位置
 * 2. 对于每个未访问的水坑位置，使用DFS标记所有相连的水坑
 * 3. 每次开始新的DFS时，计数器加1
 * 时间复杂度：O(N*M)，每个位置最多访问一次
 * 空间复杂度：O(N*M)，需要visited数组标记访问状态
 */

// 八个方向的移动向量（上、下、左、右、左上、左下、右上、右下）
const int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};

// 检查坐标是否在范围内
bool inBound(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

// DFS遍历所有相连的水坑
void dfs(int x, int y, vector<vector<char>>& field, vector<vector<bool>>& visited)
{
    visited[x][y] = true;
    
    // 遍历八个方向
    for(int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // 如果新位置在范围内、是水坑且未访问过
        if(inBound(nx, ny, field.size(), field[0].size()) && 
           field[nx][ny] == 'W' && !visited[nx][ny])
        {
            dfs(nx, ny, field, visited);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    // 读入农场地图
    vector<vector<char>> field(n, vector<char>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> field[i][j];
        }
    }
    
    // 访问标记数组
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int ponds = 0;
    
    // 遍历每个位置
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // 如果是未访问的水坑，开始新的DFS
            if(field[i][j] == 'W' && !visited[i][j])
            {
                dfs(i, j, field, visited);
                ponds++;
            }
        }
    }
    
    cout << ponds << endl;
    return 0;
}