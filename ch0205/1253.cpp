#include <bits/stdc++.h>
using namespace std;

/*
 * 三维迷宫最短路问题
 * 题目要求：在三维迷宫中找到从起点S到终点E的最短路径
 * 核心算法：BFS（广度优先搜索）
 * 1. 使用三维数组存储迷宫状态
 * 2. 使用队列进行BFS搜索
 * 3. 每个状态可以向六个方向（上下前后左右）移动
 * 时间复杂度：O(L*R*C)，其中L,R,C为迷宫三个维度的大小
 * 空间复杂度：O(L*R*C)，主要是迷宫状态和访问数组的空间
 */

// 存储位置和到达该位置所需时间
struct Node
{
    int x, y, z, t;
};

// 检查坐标是否在迷宫范围内
bool inBound(int x, int y, int z, int L, int R, int C)
{
    return x >= 0 && x < L && y >= 0 && y < R && z >= 0 && z < C;
}

// 检查该位置是否可以移动（不是墙且未访问过）
bool canMove(int x, int y, int z, const vector<vector<vector<char>>>& maze,
    const vector<vector<vector<bool>>>& vis)
{
    return maze[x][y][z] != '#' && !vis[x][y][z];
}

// 综合检查位置的有效性（在范围内且可移动）
bool isValid(int x, int y, int z, int L, int R, int C,
    const vector<vector<vector<char>>>& maze,
    const vector<vector<vector<bool>>>& vis)
{
    return inBound(x, y, z, L, R, C) && canMove(x, y, z, maze, vis);
}

int main()
{
    int L, R, C;
    while(cin >> L >> R >> C && L && R && C)
    {
        // 初始化三维迷宫和访问数组
        vector<vector<vector<char>>> maze(L, vector<vector<char>>(R,
            vector<char>(C)));
        vector<vector<vector<bool>>> vis(L,
            vector<vector<bool>>(R, vector<bool>(C)));
        queue<Node> q;
        Node start;

        // 读入迷宫，同时找到起点S的位置
        for(int i = 0; i < L; i++)
        {
            for(int j = 0; j < R; j++)
            {
                for(int k = 0; k < C; k++)
                {
                    cin >> maze[i][j][k];
                    if(maze[i][j][k] == 'S')
                    {
                        start = {i, j, k, 0};
                        q.push(start);
                        vis[i][j][k] = true;
                    }
                }
            }
        }

        // 定义六个方向的移动向量（上下前后左右）
        int dx[] = {1, -1, 0, 0, 0, 0};
        int dy[] = {0, 0, 1, -1, 0, 0};
        int dz[] = {0, 0, 0, 0, 1, -1};

        // BFS搜索最短路径
        bool found = false;
        while(!q.empty() && !found)
        {
            auto cur = q.front();
            q.pop();
            // 如果到达终点E，输出所需时间
            if(maze[cur.x][cur.y][cur.z] == 'E')
            {
                cout << "Escaped in " << cur.t << " minute(s)." << endl;
                found = true;
                break;
            }
            else
            {
                // 尝试六个方向的移动
                for(int i = 0; i < 6; i++)
                {
                    int nx = cur.x + dx[i];
                    int ny = cur.y + dy[i];
                    int nz = cur.z + dz[i];

                    // 如果新位置有效，加入队列
                    if(isValid(nx, ny, nz, L, R, C, maze, vis))
                    {
                        vis[nx][ny][nz] = true;
                        q.push({nx, ny, nz, cur.t + 1});
                    }
                }
            }
        }

        // 如果没有找到路径，输出Trapped
        if(!found)
        {
            cout << "Trapped!" << endl;
        }
    }
    return 0;
}