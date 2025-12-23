#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 5;
int maze[N][N];
// 用于记录每个点的前驱节点
struct Point
{
    int x, y;
    Point* prev; // 指向前一个位置
    Point(int x = 0, int y = 0, Point* p = nullptr) : x(x), y(y), prev(p)
    {
    }
};

// 四个方向：上、右、下、左
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

// 判断坐标是否在迷宫内且可以走
bool isValid(int x, int y)
{
    // TODO: 实现此函数，判断(x,y)是否是有效位置
    return x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0;
}

// 使用BFS寻找最短路径
void findPath()
{
    // 用于记录已访问的点
    bool visited[N][N] = {false};

    queue<Point*> q;
    Point* start = new Point(0, 0);
    q.push(start);
    visited[0][0] = true;

    Point* endPoint = nullptr; // 用于存储到达终点时的Point指针

    while(!q.empty() && endPoint == nullptr)
    {
        Point* cur = q.front();
        q.pop();

        // 如果到达终点
        if(cur->x == N - 1 && cur->y == N - 1)
        {
            endPoint = cur;
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            int x = cur->x + dx[i];
            int y = cur->y + dy[i];
            if(isValid(x, y) && !visited[x][y])
            {
                Point* next = new Point(x, y, cur);
                q.push(next);
                visited[x][y] = true;
            }
        }
    }

    if(endPoint != nullptr)
    {
        // 存储路径
        vector<Point*> path;
        Point* p = endPoint;
        while(p != nullptr)
        {
            path.push_back(p);
            p = p->prev;
        }

        // 反向输出路径
        for(int i = path.size() - 1; i >= 0; i--)
        {
            cout << "(" << path[i]->x << ", " << path[i]->y << ")" << endl;
        }
    }
}

int main()
{
    // 读入迷宫
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> maze[i][j];

    // 寻找并输出路径
    findPath();

    return 0;
}