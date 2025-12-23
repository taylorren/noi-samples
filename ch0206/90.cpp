#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int R, C;
vector<vector<int>> height;
vector<vector<int>> dp;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

int dfs(int x, int y)
{
    if(dp[x][y] != -1)
        return dp[x][y];
    dp[x][y] = 1; // 初始长度为1
    for(int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < R && ny >= 0 && ny < C &&
           height[nx][ny] < height[x][y])
        {
            dp[x][y] = max(dp[x][y], 1 + dfs(nx, ny));
        }
    }
    return dp[x][y];
}

int main()
{
    cin >> R >> C;
    height.resize(R, vector<int>(C));
    dp.resize(R, vector<int>(C, -1));

    for(int i = 0; i < R; ++i)
    {
        for(int j = 0; j < C; ++j)
        {
            cin >> height[i][j];
        }
    }

    int longest = 0;
    for(int i = 0; i < R; ++i)
    {
        for(int j = 0; j < C; ++j)
        {
            longest = max(longest, dfs(i, j));
        }
    }

    cout << longest << endl;
    return 0;
}