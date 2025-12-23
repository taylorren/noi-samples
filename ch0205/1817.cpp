#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 55;
int m, n;                 // m是南北向，n是东西向的方块数
int castle[MAXN][MAXN];   // 存储每个方块的墙的情况
bool visited[MAXN][MAXN]; // 标记是否访问过
int roomCount = 0;        // 房间数量
int maxRoomSize = 0;      // 最大房间大小

// 检查(x,y)位置是否有某个方向的墙
// direction: 1=西，2=北，4=东，8=南
bool hasWall(int x, int y, int direction)
{
    return (castle[x][y] & direction) != 0;
}

// 使用BFS计算一个房间的大小
int bfs(int startX, int startY)
{
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    int size = 0;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        size++;

        // 检查四个方向
        // 西方
        if(y > 0 && !hasWall(x, y, 1) && !visited[x][y - 1])
        {
            visited[x][y - 1] = true;
            q.push({x, y - 1});
        }
        // 北方
        if(x > 0 && !hasWall(x, y, 2) && !visited[x - 1][y])
        {
            visited[x - 1][y] = true;
            q.push({x - 1, y});
        }
        // 东方
        if(y < n - 1 && !hasWall(x, y, 4) && !visited[x][y + 1])
        {
            visited[x][y + 1] = true;
            q.push({x, y + 1});
        }
        // 南方
        if(x < m - 1 && !hasWall(x, y, 8) && !visited[x + 1][y])
        {
            visited[x + 1][y] = true;
            q.push({x + 1, y});
        }
    }
    return size;
}

int main()
{
    // 读入数据
    cin >> m >> n;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> castle[i][j];
        }
    }

    // 遍历所有方块，找出所有房间
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                roomCount++;
                int roomSize = bfs(i, j);
                maxRoomSize = max(maxRoomSize, roomSize);
            }
        }
    }

    // 输出结果
    cout << roomCount << endl;
    cout << maxRoomSize << endl;

    return 0;
}