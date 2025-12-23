#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 205;
const int INF = 0x3f3f3f3f;
char maze[MAXN][MAXN]; // 迷宫
int dist[MAXN][MAXN];  // 到达每个点的最短时间
int n, m;              // 行数和列数
int sx, sy;            // 骑士起点
int ex, ey;            // 公主位置

// 方向数组：上下左右
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct Point
{
    int x, y; // 坐标
    int time; // 到达该点的时间
    Point(int _x, int _y, int _t) : x(_x), y(_y), time(_t)
    {
    }
};

// 判断某个位置是否可以访问
bool canVisit(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != '#';
}

// 计算从起点到终点的最短时间
int bfs()
{
    // 初始化距离为无穷大
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dist[i][j] = INF;

    queue<Point> q;

    // 将起点加入队列
    q.push(Point(sx, sy, 0));
    dist[sx][sy] = 0;

    while(!q.empty())
    {
        Point cur = q.front();
        q.pop();

        // 尝试四个方向
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(canVisit(nx, ny))
            {
                // 计算到达新位置的时间
                int nt = cur.time + 1; // 移动一步
                if(maze[nx][ny] == 'x')
                {
                    nt++; // 遇到守卫多花1单位时间
                }

                // 如果找到更短路径
                if(nt < dist[nx][ny])
                {
                    dist[nx][ny] = nt;
                    q.push(Point(nx, ny, nt));
                }
            }
        }
    }

    return dist[ex][ey] == INF ? -1 : dist[ex][ey];
}

int main()
{
    int S;
    cin >> S;
    while(S--)
    {
        // 读入迷宫
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> maze[i][j];
                if(maze[i][j] == 'r')
                {
                    sx = i;
                    sy = j; // 记录骑士位置
                }
                if(maze[i][j] == 'a')
                {
                    ex = i;
                    ey = j; // 记录公主位置
                }
            }
        }

        // 计算结果
        int ans = bfs();
        if(ans == -1)
            cout << "Impossible" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}