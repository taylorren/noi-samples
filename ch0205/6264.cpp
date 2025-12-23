#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 105;
char maze[MAXN][MAXN]; // 迷宫
int dist[MAXN][MAXN];  // 到达每个点的最短距离
int n, m;              // 行数和列数
int sx, sy;            // 起点坐标
int ex, ey;            // 终点坐标

// 方向数组：上下左右
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct Point
{
    int x, y; // 坐标
    Point(int _x, int _y) : x(_x), y(_y)
    {
    }
};

// TODO: 判断某个位置是否可以访问
bool canVisit(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m &&
            maze[x][y] != '#'); // 请补充代码：检查位置是否合法，是否是墙
}

// TODO: 计算从起点到终点的最短距离
int bfs()
{
    // 1. 初始化dist数组为-1（表示未访问）
    memset(dist, -1, sizeof(dist));
    
    // 2. 将起点加入队列
    queue<Point> q;
    q.push(Point(sx, sy));
    dist[sx][sy] = 0;  // 起点距离为0
    
    // 3. BFS搜索，直到找到终点或队列为空
    while(!q.empty())
    {
        Point cur = q.front();
        q.pop();
        
        // 如果到达终点，立即返回
        if(cur.x == ex && cur.y == ey)
        {
            return dist[cur.x][cur.y];
        }
        
        // 尝试四个方向
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            // 只访问未访问过的可行点
            if(canVisit(nx, ny) && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                q.push(Point(nx, ny));
            }
        }
    }
    
    return -1;  // 无法到达终点
}

int main()
{
    // 读入迷宫
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            if(maze[i][j] == 'S')
            {
                sx = i;
                sy = j; // 记录起点
            }
            if(maze[i][j] == 'T')
            {
                ex = i;
                ey = j; // 记录终点
            }
        }
    }

    // 计算结果
    cout << bfs() << endl;

    return 0;
}