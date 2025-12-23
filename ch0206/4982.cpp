#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// 使用哈希表记录已访问的点
unordered_map<string, bool> visited;
int n;
long long ans = 0;

// 获取坐标的字符串表示，用于哈希表的key
string getKey(int x, int y) {
    return to_string(x) + "," + to_string(y);
}

// DFS搜索
void dfs(int x, int y, int steps) {
    if (steps == n) {
        ans++;
        return;
    }
    
    // 三个可能的方向：北(0,1), 东(1,0), 西(-1,0)
    int dx[] = {0, 1, -1};
    int dy[] = {1, 0, 0};
    
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        string key = getKey(nx, ny);
        
        if (!visited[key]) {
            visited[key] = true;
            dfs(nx, ny, steps + 1);
            visited[key] = false;
        }
    }
}

int main() {
    cin >> n;
    
    // 起点设为(0,0)并标记为已访问
    visited[getKey(0, 0)] = true;
    dfs(0, 0, 0);
    
    cout << ans << endl;
    return 0;
}