/*
 * 马遍历棋盘问题
 * 使用DFS回溯算法，搜索所有可能的遍历路径
 * 马按日字形移动，不能重复经过同一个点
 */
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 10;
int n, m;           // 棋盘大小
int startX, startY; // 起始位置
bool visited[MAXN][MAXN];  // 记录是否访问过
long long ans;      // 记录总路径数

// 马的8种移动方向（日字形）
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

// 检查位置是否在棋盘内
bool inBoard(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

// DFS搜索所有可能路径
void dfs(int x, int y, int step) {
    // 如果已经遍历了所有点，找到一条有效路径
    if (step == n * m) {
        ans++;
        return;
    }

    // 尝试8个方向
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // 如果新位置合法且未访问过
        if (inBoard(nx, ny) && !visited[nx][ny]) {
            visited[nx][ny] = true;  // 标记访问
            dfs(nx, ny, step + 1);   // 继续搜索
            visited[nx][ny] = false; // 回溯，取消标记
        }
    }
}

void solve() {
    // 初始化
    memset(visited, false, sizeof(visited));
    ans = 0;
    
    // 标记起始位置为已访问
    visited[startX][startY] = true;
    
    // 从起始位置开始DFS
    dfs(startX, startY, 1);
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        // 读入棋盘大小和起始位置
        cin >> n >> m >> startX >> startY;
        
        // 求解
        solve();
        
        // 输出结果
        cout << ans << endl;
    }
    
    return 0;
}