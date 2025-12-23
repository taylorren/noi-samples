#include <iostream>
using namespace std;

// 递归函数：m个苹果放在n个盘子里的方案数
int solve(int m, int n)
{
    // 基础情况
    if(m == 0)
        return 1; // 0个苹果只有1种放法
    if(n == 1)
        return 1; // 1个盘子只有1种放法

    if(m < n)
    {
        // 苹果数小于盘子数，一定有盘子空着
        // 相当于m个苹果放在m个盘子里
        return solve(m, m);
    }
    else
    {
        // 情况1：至少有一个盘子空着
        // 情况2：每个盘子至少放一个苹果
        return solve(m, n - 1) + solve(m - n, n);
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int m, n;
        cin >> m >> n;
        cout << solve(m, n) << endl;
    }

    return 0;
}