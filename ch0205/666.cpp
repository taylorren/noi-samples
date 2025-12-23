#include <iostream>
using namespace std;

// dfs(m, n)表示m个苹果放n个盘子的方案数
// 每次可以选择：1. 空出一个盘子 2. 每个盘子放一个苹果
int dfs(int m, int n) {
    if(n == 0 || m < 0) {
        return 0;
    }
    if(m == 0) {
        return 1;
    }
    if(n == 1) {
        return 1;
    }
    
    return dfs(m, n-1) + dfs(m-n, n);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        cin >> m >> n;
        cout << dfs(m, n) << endl;
    }
    return 0;
}