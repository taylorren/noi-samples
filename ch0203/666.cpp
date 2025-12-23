#include <iostream>
using namespace std;

int solve(int m, int n) {
    // 如果没有盘子，或者苹果数为负数，方案数为0
    if(n == 0 || m < 0) return 0;
    // 如果没有苹果，只有一种方案（都不放）
    if(m == 0) return 1;
    // 如果只有一个盘子，只有一种方案（都放在这个盘子里）
    if(n == 1) return 1;
    
    // 递推：
    // 1. 至少有一个空盘的情况：f(m,n-1)
    // 2. 每个盘子至少放一个的情况：f(m-n,n)
    return solve(m, n-1) + solve(m-n, n);
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int m, n;
        cin >> m >> n;
        cout << solve(m, n) << endl;
    }
    
    return 0;
}