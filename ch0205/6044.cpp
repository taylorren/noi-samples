#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 205;
const int INF = 0x3f3f3f3f;
char maze[MAXN][MAXN]; // 地图
int dist[MAXN][MAXN][10]; // 状态：x,y位置且剩余chakra查克拉时的最短时间
int n, m, chakra; // 行数、列数和初始查克拉
int sx, sy;       // 鸣人起点
int ex, ey;       // 佐助位置

// 方向数组：上下左右
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct Point
{
    int x, y;   // 坐标
    int chakra; // 剩余查克拉
    int time;   // 到达时间
    Point(int _x, int _y, int _c, int _t) : x(_x), y(_y), chakra(_c), time(_t)
    {
    }
};

// 判断某个位置是否可以访问
bool canVisit(int x, int y, int chakra)
{
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if(maze[x][y] == '#' && chakra <= 0)
        return false; // 没有查克拉时不能走到有大蛇丸手下的位置
    return true;
}

// 计算最短时间
int bfs()
{
    // 初始化距离为无穷大
    memset(dist, 0x3f, sizeof(dist));

    queue<Point> q;

    // 将起点加入队列
    q.push(Point(sx, sy, chakra, 0)); // 使用chakra代替t
    dist[sx][sy][chakra] = 0;

    while(!q.empty())
    {
        Point cur = q.front();
        q.pop();

        // 如果到达佐助位置
        if(cur.x == ex && cur.y == ey)
        {
            return cur.time;
        }

        // 尝试四个方向
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(canVisit(nx, ny, cur.chakra))
            {
                // 计算移动后的状态
                int nc = cur.chakra;
                if(maze[nx][ny] == '#')
                    nc--; // 消耗查克拉

                // 如果找到更短路径
                if(cur.time + 1 < dist[nx][ny][nc])
                {
                    dist[nx][ny][nc] = cur.time + 1;
                    q.push(Point(nx, ny, nc, cur.time + 1));
                }
            }
        }
    }

    return -1; // 无法到达
}

int main()
{
    // 读入数据
    cin >> n >> m >> chakra; // 使用chakra代替t
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            if(maze[i][j] == '@')
            {
                sx = i;
                sy = j;           // 记录鸣人位置
                maze[i][j] = '*'; // 将起点标记为通路
            }
            if(maze[i][j] == '+')
            {
                ex = i;
                ey = j;           // 记录佐助位置
                maze[i][j] = '*'; // 将终点标记为通路
            }
        }
    }

    // 计算结果
    cout << bfs() << endl;

    return 0;
}