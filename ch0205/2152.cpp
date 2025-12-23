#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

// 状态结构体
struct State {
    int x, y;          // 两个壶中的水量
    vector<string> ops; // 操作序列
    State(int _x, int _y) : x(_x), y(_y) {}
};

// 检查是否达到目标
bool check(int x, int y, int c) {
    return x == c || y == c;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    // 如果目标水量大于两个壶中较大的那个，无解
    if (c > max(a, b)) {
        cout << "impossible" << endl;
        return 0;
    }

    queue<State> q;
    map<pair<int,int>, bool> visited;
    
    // 初始状态：两个壶都是空的
    State initial(0, 0);
    q.push(initial);
    visited[{0, 0}] = true;
    
    // BFS搜索
    while (!q.empty()) {
        State curr = q.front();
        q.pop();
        
        // 找到解
        if (check(curr.x, curr.y, c)) {
            cout << curr.ops.size() << endl;
            for (const string& op : curr.ops) {
                cout << op << endl;
            }
            return 0;
        }

        // TODO: 在这里实现6种操作的状态转移
        // 1. FILL(1)
        int new_x=a;
        
        if(!visited[{new_x, curr.y}])
        {
            visited[{new_x, curr.y}] = true;
            State new_state(new_x, curr.y);
            new_state.ops = curr.ops;
            new_state.ops.push_back("FILL(1)");
            q.push(new_state);
        }
        // 2. FILL(2)
        int new_y=b;
        if(!visited[{curr.x, new_y}])
        {
            visited[{curr.x, new_y}] = true;
            State new_state(curr.x, new_y);
            new_state.ops = curr.ops;
            new_state.ops.push_back("FILL(2)");
            q.push(new_state);
        }
        // 3. DROP(1)
        new_x=0;
        if(!visited[{new_x, curr.y}])
        {
            visited[{new_x, curr.y}] = true;
            State new_state(new_x, curr.y);
            new_state.ops = curr.ops;
            new_state.ops.push_back("DROP(1)");
            q.push(new_state);
        }
        // 4. DROP(2)
        new_y=0;
        if(!visited[{curr.x, new_y}])
        {
            visited[{curr.x, new_y}] = true;
            State new_state(curr.x, new_y);
            new_state.ops = curr.ops;
            new_state.ops.push_back("DROP(2)");
            q.push(new_state);
        }
        // 5. POUR(1,2)
        if(curr.x+curr.y<=b)
        {
            new_x=0;
            new_y=curr.x+curr.y;
            if(!visited[{new_x, new_y}])
            {
                visited[{new_x, new_y}] = true;
                State new_state(new_x, new_y);
                new_state.ops = curr.ops;
                new_state.ops.push_back("POUR(1,2)");
                q.push(new_state);
            }
        }
        else
        {
            new_y=b;
            new_x=curr.x+curr.y-b;
            if(!visited[{new_x, new_y}])
            {
                visited[{new_x, new_y}] = true;
                State new_state(new_x, new_y);
                new_state.ops = curr.ops;
                new_state.ops.push_back("POUR(1,2)");
                q.push(new_state);
            }
        }
        // 6. POUR(2,1)
        if(curr.x+curr.y<=a)
        {
            new_y=0;
            new_x=curr.x+curr.y;
            if(!visited[{new_x, new_y}])
            {
                visited[{new_x, new_y}] = true;
                State new_state(new_x, new_y);
                new_state.ops = curr.ops;
                new_state.ops.push_back("POUR(2,1)");
                q.push(new_state);
            }
        }
        else
        {
            new_x=a;
            new_y=curr.x+curr.y-a;
            if(!visited[{new_x, new_y}])
            {
                visited[{new_x, new_y}] = true;
                State new_state(new_x, new_y);
                new_state.ops = curr.ops;
                new_state.ops.push_back("POUR(2,1)");
                q.push(new_state);
            }
        }
        
        // 提示：对于每种操作
        // 1. 计算新状态(new_x, new_y)
        // 2. 如果这个状态没访问过:
        //    - 标记为已访问
        //    - 复制当前操作序列
        //    - 添加新操作
        //    - 将新状态加入队列
    }
    
    cout << "impossible" << endl;
    return 0;
}