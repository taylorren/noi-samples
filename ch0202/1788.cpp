#include <iostream>
using namespace std;

const int MOD = 32767;

// 计算第k项Pell数
int pell(int k)
{
    if(k == 1)
        return 1;
    if(k == 2)
        return 2;

    // 使用动态规划避免递归
    int prev2 = 1; // a[n-2]
    int prev1 = 2; // a[n-1]
    int curr;      // a[n]

    // 从第3项开始计算到第k项
    for(int i = 3; i <= k; i++)
    {
        // a[n] = 2 * a[n-1] + a[n-2]
        // 在计算过程中进行模运算避免溢出
        curr = (2 * prev1 % MOD + prev2) % MOD;

        // 更新前两项的值
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int n;
    cin >> n;

    // 处理n组测试数据
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        cout << pell(k) << endl;
    }

    return 0;
}