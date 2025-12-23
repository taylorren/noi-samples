#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

const int MAXN = 50;

// 方向数组：下、上、右、左
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

// 位置结构体
struct Position
{
    int x, y;
    Position(int x = 0, int y = 0) : x(x), y(y) {}
};

class Maze
{
private:
    vector<string> grid;
    vector<vector<bool>> visited;
    vector<int> keyCount; // 每种门需要的钥匙数量
    int n, m;
    Position start;

public:
    // 读取迷宫数据
    bool read()
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            return false;

        // 初始化数据结构
        grid.resize(n + 2);
        visited.assign(n + 2, vector<bool>(m + 2, false));
        keyCount.assign(6, 0); // 5种钥匙 + 1（为了方便索引）

        // 读取迷宫
        string line;
        for (int i = 1; i <= n; i++)
        {
            cin >> line;
            grid[i] = " " + line + " "; // 添加边界

            // 统计钥匙和起点
            for (int j = 1; j <= m; j++)
            {
                if (grid[i][j] >= 'a' && grid[i][j] <= 'e')
                {
                    keyCount[grid[i][j] - 'a' + 1]++;
                }
                else if (grid[i][j] == 'S')
                {
                    start = Position(i, j);
                }
            }
        }

        // 添加上下边界
        grid[0] = string(m + 2, ' ');
        grid[n + 1] = string(m + 2, ' ');
        return true;
    }

    // BFS搜索
    bool findTreasure()
    {
        queue<Position> Q;
        Q.push(start);
        visited[start.x][start.y] = true;
        int steps = 0;
        const int MAX_STEPS = 1000; // 限制步数

        while (!Q.empty() && steps < MAX_STEPS)
        {
            Position curr = Q.front();
            Q.pop();
            steps++;

            // 处理当前位置是门的情况
            if (grid[curr.x][curr.y] >= 'A' && grid[curr.x][curr.y] <= 'E')
            {
                if (keyCount[grid[curr.x][curr.y] - 'A' + 1] == 0)
                {
                    visited[curr.x][curr.y] = true;
                }
                else
                {
                    Q.push(curr);
                    continue;
                }
            }

            // 尝试四个方向
            for (int i = 0; i < 4; i++)
            {
                Position next(curr.x + dx[i], curr.y + dy[i]);

                if (isValidMove(next))
                {
                    char cell = grid[next.x][next.y];

                    // 找到宝藏
                    if (cell == 'G')
                        return true;

                    // 处理不同类型的格子
                    if (cell >= 'A' && cell <= 'E')
                    {
                        Q.push(next);
                    }
                    else if (cell >= 'a' && cell <= 'e')
                    {
                        keyCount[cell - 'a' + 1]--;
                        visited[next.x][next.y] = true;
                        Q.push(next);
                    }
                    else if (cell == '.')
                    {
                        visited[next.x][next.y] = true;
                        Q.push(next);
                    }
                }
            }
        }
        return false;
    }

private:
    // 检查移动是否有效
    bool isValidMove(const Position &pos)
    {
        return pos.x >= 1 && pos.x <= n &&
               pos.y >= 1 && pos.y <= m &&
               !visited[pos.x][pos.y];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Maze maze;
    while (maze.read())
    {
        cout << (maze.findTreasure() ? "YES" : "NO") << endl;
    }

    return 0;
}