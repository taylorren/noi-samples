#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    
    vector<int> distance(N + 1, -1);  // 初始化为-1，表示未访问
    vector<vector<int>> children(N + 1);  // 存储每根管道的子管道
    
    // 读取连接信息
    for (int i = 0; i < C; i++) {
        int E, B1, B2;
        cin >> E >> B1 >> B2;
        children[E].push_back(B1);
        children[E].push_back(B2);
    }
    
    // 管道1连接谷仓，距离为1
    distance[1] = 1;
    
    // 使用BFS计算距离
    queue<int> q;
    q.push(1);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        // 处理当前管道的所有子管道
        for (int child : children[current]) {
            if (distance[child] == -1) {  // 未访问过
                distance[child] = distance[current] + 1;
                q.push(child);
            }
        }
    }
    
    // 输出结果
    for (int i = 1; i <= N; i++) {
        if (distance[i] == -1) {
            cout << 0 << endl;
        } else {
            cout << distance[i] << endl;
        }
    }
    
    return 0;
}