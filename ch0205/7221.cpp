#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 205;
const int dx[] = {-1, 0, 1, 0}; // 4 directions: up, right, down, left
const int dy[] = {0, 1, 0, -1};

// Structure to represent a state in the search
struct State
{
    int x, y; // current position
    int gems; // bitmask for collected gems
    int dist; // distance traveled
    State(int x = 0, int y = 0, int g = 0, int d = 0)
        : x(x), y(y), gems(g), dist(d)
    {
    }
};

int R, C, K;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN][32]; // position + gem state
vector<pair<int, int>> teleports;

// TODO: Implement this function to check if position (x,y) is valid
bool isValid(int x, int y)
{
    // Return true if position is within bounds and not a wall (#)
    return (x >= 0 && x < R && y >= 0 && y < C && grid[x][y] != '#');
}

// Main search function
int bfs(int startX, int startY, int endX, int endY)
{
    memset(visited, 0, sizeof(visited));
    queue<State> q;
    q.push(State(startX, startY, 0, 0));
    visited[startX][startY][0] = true;

    while(!q.empty())
    {
        State curr = q.front();
        q.pop();

        if(grid[curr.x][curr.y] == 'E')
        {
            int gemType = 0;
            for(int i = 0; i < 5; i++)
            {
                if(curr.gems & (1 << i))
                {
                    gemType++;
                }
            }
            if(gemType >= K) // 宝石种类够了
            {
                return curr.dist;
            }
        }

        // 处理传送门
        if(grid[curr.x][curr.y] == '$')
        {
            for(const auto& tp : teleports)
            {
                if(tp.first == curr.x && tp.second == curr.y)
                {
                    continue;
                }

                if(!visited[tp.first][tp.second][curr.gems])
                {
                    visited[tp.first][tp.second][curr.gems] = true;
                    q.push(State(tp.first, tp.second, curr.gems, curr.dist));
                }
            }
        }

        // 处理普通移动
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = curr.x + dx[dir];
            int ny = curr.y + dy[dir];

            if(isValid(nx, ny))
            {
                int gems=curr.gems;
                if(grid[nx][ny] >= '0' && grid[nx][ny] <= '4')//这里有宝石
                {
                    gems|=(1<<(grid[nx][ny]-'0'));
                }

                State next(nx, ny, gems, curr.dist + 1);
                if(!visited[next.x][next.y][next.gems])
                {
                    visited[next.x][next.y][next.gems] = true;
                    q.push(next);
                }
            }
        }
    }
    
    return -1; // impossible to reach
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        // 读取地图大小和所需宝石数
        cin >> R >> C >> K;
        teleports.clear();
        int startX, startY, endX, endY;
        
        // 读取地图
        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                cin >> grid[i][j];
                if(grid[i][j] == 'S')
                {
                    startX = i;
                    startY = j;
                }
                else if(grid[i][j] == 'E')
                {
                    endX = i;
                    endY = j;
                }
                else if(grid[i][j] == '$')
                {
                    teleports.push_back({i, j});
                }
            }
        }

        // 寻找最短路径
        int result = bfs(startX, startY, endX, endY);
        
        // 输出结果
        if(result == -1)
        {
            cout << "oop!" << endl;
        }
        else
        {
            cout << result << endl;
        }
    }
    return 0;
}