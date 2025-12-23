#include <bits/stdc++.h>
using namespace std;

// 骑士的8个可能移动方向
const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool canMove(int x, int y, int l) {
    return x >= 0 && x < l && y >= 0 && y < l;
}

// 在这里实现你的BFS函数
int bfs(int startX, int startY, int endX, int endY, int l) {
    // 如果起点和终点相同，返回0
    if (startX == endX && startY == endY) return 0;
    
    // 创建访问数组，初始化为-1表示未访问
    vector<vector<int>> visited(l, vector<int>(l, -1));
    
    // 创建队列，存储坐标
    queue<pair<int, int>> q;
    
    // 将起点加入队列，并标记为已访问，步数为0
    q.push({startX, startY});
    visited[startX][startY] = 0;
    
    // BFS主循环
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // 尝试8个方向的移动
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 检查新位置是否有效且未访问
            if (canMove(nx, ny, l) && visited[nx][ny] == -1) {
                // 如果到达终点，返回步数+1
                if (nx == endX && ny == endY) {
                    return visited[x][y] + 1;
                }
                
                // 将新位置加入队列，更新步数
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return -1; // 如果无法到达
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        int l, x1, y1, x2, y2;
        cin >> l >> x1 >> y1 >> x2 >> y2;
        cout << bfs(x1, y1, x2, y2, l) << endl;
    }
    return 0;
}