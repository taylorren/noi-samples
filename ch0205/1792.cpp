#include <iostream>
using namespace std;

const int MAXN = 105;
char maze[MAXN][MAXN];
bool visited[MAXN][MAXN];
int n;
// 四个方向的移动：上、右、下、左
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool dfs(int x, int y, int endX, int endY)
{
    // 如果到达终点
    if(x == endX && y == endY)
    {
        return true;
    }

    // 尝试四个方向
    for(int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        // 检查新位置是否合法且未访问
        if(newX >= 0 && newX < n && newY >= 0 && newY < n &&
           maze[newX][newY] == '.' && !visited[newX][newY])
        {
            visited[newX][newY] = true; // 标记为已访问
            if(dfs(newX, newY, endX, endY))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int k;
    cin >> k;
    while(k--)
    {
        cin >> n;

        // 读入迷宫
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> maze[i][j];
                visited[i][j] = false; // 顺便初始化visited数组
            }
        }

        int ha, la, hb, lb;
        cin >> ha >> la >> hb >> lb;

        // 如果起点或终点是墙，直接输出NO
        if(maze[ha][la] == '#' || maze[hb][lb] == '#')
        {
            cout << "NO" << endl;
            continue;
        }

        visited[ha][la] = true; // 标记起点已访问

        // 使用DFS寻找路径
        if(dfs(ha, la, hb, lb))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}