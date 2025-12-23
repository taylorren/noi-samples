
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 25;
char grid[MAXN][MAXN];    // 存储瓷砖
bool visited[MAXN][MAXN]; // 记录访问状态
int W, H;                 // 宽度和高度

// 方向数组：上、右、下、左
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

// TODO: 实现检查位置是否合法的函数
// 提示：需要检查：
// 1. 位置是否在网格范围内
// 2. 是否是黑色瓷砖('.' 或 '@')
// 3. 是否已经访问过
bool inRange(int x, int y)
{
    return x >= 0 && x < H && y >= 0 && y < W;
}

bool isValid(int x, int y)
{
    return inRange(x, y) && (grid[x][y] == '.' || grid[x][y] == '@') &&
           !visited[x][y];
}

// TODO: 实现DFS函数来统计可到达的黑色瓷砖数量
// 提示:
// 1. 从当前位置开始，向四个方向探索
// 2. 记得标记已访问的位置
// 3. 返回可到达的瓷砖数量（包括当前位置）
int dfs(int x, int y)
{
    if(!isValid(x, y))
    {
        return 0;
    }

    visited[x][y] = true;
    int count = 1;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        count += dfs(nx, ny);
    }
    return count;
}

int main()
{
    while(true)
    {
        cin >> W >> H;
        if(W == 0 && H == 0)
            break;

        // 读入瓷砖地图
        int startX, startY; // 起始位置
        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
            {
                cin >> grid[i][j];
                if(grid[i][j] == '@')
                {
                    startX = i;
                    startY = j;
                }
                visited[i][j] = false; // 重置访问状态
            }
        }

        // 计算并输出结果
        cout << dfs(startX, startY) << endl;
    }
    return 0;
}