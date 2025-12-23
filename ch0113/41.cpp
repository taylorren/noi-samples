#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main() {
    unsigned int k, x;
    char comma; // 用于读取逗号
    cin >> k >> comma >> x; // 读取输入

    set<unsigned int> M; // 存储集合 M
    queue<unsigned int> q; // 用于 BFS

    // 初始化
    q.push(k);
    M.insert(k);

    // BFS 生成集合 M
    while (!q.empty()) {
        unsigned int current = q.front();
        q.pop();

        // 生成新元素
        unsigned int newElement1 = 2 * current + 1;
        unsigned int newElement2 = 3 * current + 1;

        // 检查新元素是否在范围内
        if (newElement1 <= 100000 && M.find(newElement1) == M.end()) {
            M.insert(newElement1);
            q.push(newElement1);
        }
        if (newElement2 <= 100000 && M.find(newElement2) == M.end()) {
            M.insert(newElement2);
            q.push(newElement2);
        }
    }

    // 判断 x 是否在集合 M 中
    if (M.find(x) != M.end()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
