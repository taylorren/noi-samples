#include <iostream>
using namespace std;

const int MAXN = 10;
char board[MAXN][MAXN]; // 棋盘，#表示可放置区域，.表示空白
bool row[MAXN];         // 记录每行是否已放置
bool col[MAXN];         // 记录每列是否已放置
int n, k;               // n是棋盘大小，k是需要放置的棋子数
int ans;                // 方案数

// pos表示当前处理到第几个格子（从0到n*n-1）
// cnt表示已经放置的棋子数
void dfs(int pos, int cnt)
{
    // 已经放置了k个棋子，找到一个解
    if(cnt == k)
    {
        ans++;
        return;
    }

    // 已经处理完所有格子但没放够k个棋子
    if(pos >= n * n)
        return;

    // 计算当前格子的行列位置
    int x = pos / n;
    int y = pos % n;

    // 处理下一个格子
    dfs(pos + 1, cnt);

    // 如果当前位置可以放置（是棋盘区域且所在行列都没有棋子）
    if(board[x][y] == '#' && !row[x] && !col[y])
    {
        row[x] = col[y] = true;  // 标记行列已使用
        dfs(pos + 1, cnt + 1);   // 放置棋子并继续搜索
        row[x] = col[y] = false; // 回溯，取消标记
    }
}

int main()
{
    while(true)
    {
        cin >> n >> k;
        if(n == -1 && k == -1)
            break;

        // 读入棋盘
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> board[i][j];
            }
        }

        // 初始化
        ans = 0;
        for(int i = 0; i < n; i++)
        {
            row[i] = col[i] = false;
        }

        // 从第一个格子开始搜索
        dfs(0, 0);

        cout << ans << endl;
    }
    return 0;
}