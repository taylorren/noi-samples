#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 45;
char maze[MAXN][MAXN];
bool visited[MAXN][MAXN];
int R, C;

// 四个方向：上、右、下、左
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

// TODO: 定义Point结构体
// 需要存储：
// 1. x坐标
// 2. y坐标
// 3. 从起点到当前点的步数
struct Point
{
    int x, y, step;
    Point(int _x, int _y, int _step) : x(_x), y(_y), step(_step)
    {
    }
};

// TODO: 实现isValid函数
// 检查坐标是否在迷宫范围内且可以通行
bool isValid(int x, int y)
{
    return x >= 0 && x < R && y >= 0 && y < C && maze[x][y] != '#' &&
           !visited[x][y];
}

// TODO: 实现BFS函数
// 从(0,0)到(R-1,C-1)的最短路径
int bfs()
{
    // 1. 初始化visited数组（可选）
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            visited[i][j] = false;
        }
    }
    // 2. 创建队列并加入起点(0,0)
    queue<Point> q;
    q.push({0, 0, 1});
    visited[0][0] = true;
    // 3. BFS主循环：
    //    - 取出当前点
    //    - 如果是终点(R-1,C-1)，返回步数
    //    - 否则尝试四个方向
    while(!q.empty())
    {
        Point p = q.front();
        q.pop();
        if(p.x == R - 1 && p.y == C - 1)
        {
            return p.step;
        }
        for(int i = 0; i < 4; i++)
        {
            int newX = p.x + dx[i];
            int newY = p.y + dy[i];
            if(isValid(newX, newY))
            {
                q.push({newX, newY, p.step + 1});
                visited[newX][newY] = true;
            }
        }
    }
    return -1; // 如果没有找到路径，返回-1
}

int main()
{
    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> maze[i][j];
        }
    }

    cout << bfs() << endl;
    return 0;
}