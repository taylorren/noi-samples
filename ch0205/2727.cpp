
#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 25;
char maze[MAXN][MAXN];
bool visited[MAXN][MAXN];
int m, n;

// 四个方向：上、右、下、左
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

// 提示：你需要定义一个结构体来存储：
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

// 检查坐标是否在迷宫范围内且可以通行
bool isValid(int x, int y)
{
    // TODO: 完成此函数
    return x >= 0 && x < m && y >= 0 && y < n && maze[x][y] != '#';
}

int bfs(int startX, int startY)
{
    // TODO: 实现BFS搜索
    // 1. 初始化visited数组
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }

    // 2. 创建队列并加入起点
    queue<Point> q;
    q.push(Point(startX, startY, 0));
    visited[startX][startY] = true;

    // 3. BFS主循环：
    while(!q.empty())
    {
        Point cur = q.front();
        q.pop();

        if(maze[cur.x][cur.y] == '*')
        {
            return cur.step;
        }

        for(int direction = 0; direction < 4; direction++)
        {
            int newX = cur.x + dx[direction];
            int newY = cur.y + dy[direction];
            if(isValid(newX, newY) && !visited[newX][newY])
            {
                visited[newX][newY] = true;
                q.push(Point(newX, newY, cur.step + 1));
            }
        }
    }

    return -1;
    //    - 取出当前点
    //    - 如果是终点(*)，返回步数
    //    - 否则尝试四个方向
    // 4. 如果无法到达终点，返回-1
}

int main()
{
    while(true)
    {
        cin >> m >> n;
        if(m == 0 && n == 0)
            break;

        // 读入迷宫
        int startX, startY;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> maze[i][j];
                if(maze[i][j] == '@')
                {
                    startX = i;
                    startY = j;
                }
            }
        }

        // 输出结果
        cout << bfs(startX, startY) << endl;
    }
    return 0;
}