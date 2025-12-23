#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 9;
const int MAXSTEP = 8;

struct State {
    int x[4], y[4], step;
    State() { step = 0; }
    
    // 将状态标准化（排序）并编码
    long long encode() {
        pair<int,int> pos[4];
        for(int i = 0; i < 4; i++) {
            pos[i] = make_pair(x[i], y[i]);
        }
        sort(pos, pos + 4);
        
        long long code = 0;
        for(int i = 0; i < 4; i++) {
            code = (code << 8) | (pos[i].first);
            code = (code << 8) | (pos[i].second);
        }
        return code;
    }
    
    bool operator==(const State& other) const {
        State s1 = *this;
        State s2 = other;
        return s1.encode() == s2.encode();
    }
};

// 检查坐标是否合法
bool isValid(int x, int y) {
    return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}

// 检查是否可以移动到目标位置
bool canMove(const State& s, int piece, int nx, int ny) {
    if(!isValid(nx, ny)) return false;
    
    // 检查目标位置是否已有棋子
    for(int i = 0; i < 4; i++) {
        if(s.x[i] == nx && s.y[i] == ny) return false;
    }
    return true;
}

bool bfs(State& start, State& target) {
    queue<State> q;
    set<long long> visited;
    
    q.push(start);
    visited.insert(start.encode());
    
    const int dx[] = {-1, 1, 0, 0};  // 上下左右
    const int dy[] = {0, 0, -1, 1};
    
    while(!q.empty()) {
        State cur = q.front();
        q.pop();
        
        if(cur == target) return true;
        if(cur.step >= MAXSTEP) continue;
        
        // 尝试移动每个棋子
        for(int i = 0; i < 4; i++) {
            for(int dir = 0; dir < 4; dir++) {
                // 尝试普通移动
                State next = cur;
                next.x[i] += dx[dir];
                next.y[i] += dy[dir];
                
                if(canMove(cur, i, next.x[i], next.y[i])) {
                    next.step = cur.step + 1;
                    long long code = next.encode();
                    if(visited.find(code) == visited.end()) {
                        visited.insert(code);
                        q.push(next);
                    }
                }
                
                // 尝试跳跃移动
                if(isValid(cur.x[i] + dx[dir], cur.y[i] + dy[dir])) {  // 检查中间位置是否合法
                    bool hasMiddlePiece = false;
                    int midX = cur.x[i] + dx[dir];
                    int midY = cur.y[i] + dy[dir];
                    
                    // 检查中间位置是否有棋子
                    for(int j = 0; j < 4; j++) {
                        if(j != i && cur.x[j] == midX && cur.y[j] == midY) {
                            hasMiddlePiece = true;
                            break;
                        }
                    }
                    
                    if(hasMiddlePiece) {
                        next = cur;
                        next.x[i] = midX + dx[dir];
                        next.y[i] = midY + dy[dir];
                        
                        if(canMove(cur, i, next.x[i], next.y[i])) {
                            next.step = cur.step + 1;
                            long long code = next.encode();
                            if(visited.find(code) == visited.end()) {
                                visited.insert(code);
                                q.push(next);
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    State start, target;
    
    // 读入初始状态
    for(int i = 0; i < 4; i++) {
        scanf("%d%d", &start.x[i], &start.y[i]);
    }
    
    // 读入目标状态
    for(int i = 0; i < 4; i++) {
        scanf("%d%d", &target.x[i], &target.y[i]);
    }
    
    // BFS搜索是否可达
    printf("%s\n", bfs(start, target) ? "YES" : "NO");
    
    return 0;
}