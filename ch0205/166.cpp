#include <iostream>
#include <vector>
using namespace std;

/*
 * 城堡问题：计算房间数量和最大房间面积
 * 输入：每个模块用0-15的数字表示墙的存在情况
 * - 1: 西墙
 * - 2: 北墙
 * - 4: 东墙
 * - 8: 南墙
 * 使用DFS遍历所有连通的模块来统计房间
 */

// 四个方向：西、北、东、南
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
// 对应的墙的值：西1、北2、东4、南8
const int walls[] = {1, 2, 4, 8};

// DFS遍历房间，返回房间大小
int dfs(int x, int y, vector<vector<int>>& castle, vector<vector<bool>>& visited)
{
    if(visited[x][y])
        return 0;
        
    visited[x][y] = true;
    int size = 1;  // 当前模块算一个单位
    
    // 检查四个方向
    for(int i = 0; i < 4; i++)
    {
        // 如果当前方向没有墙
        if(!(castle[x][y] & walls[i]))
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 如果新位置在城堡内且未访问过
            if(nx >= 0 && nx < castle.size() && ny >= 0 && ny < castle[0].size())
            {
                size += dfs(nx, ny, castle, visited);
            }
        }
    }
    
    return size;
}

int main()
{
    int m, n;
    cin >> m >> n;  // m行n列
    
    // 读入城堡地图
    vector<vector<int>> castle(m, vector<int>(n));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> castle[i][j];
        }
    }
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int rooms = 0;      // 房间数量
    int maxSize = 0;    // 最大房间面积
    
    // 遍历所有模块
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                rooms++;  // 发现新房间
                // 计算房间大小并更新最大值
                maxSize = max(maxSize, dfs(i, j, castle, visited));
            }
        }
    }
    
    cout << rooms << endl << maxSize << endl;
    
    return 0;
}