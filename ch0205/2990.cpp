#include <iostream>
using namespace std;

const int MAXN = 30;
int a[MAXN][MAXN];
int n, sum = 0, sum1 = 0;

// 计算下面各行并检查
void check()
{
    int t = n;
    int sum2 = 0;
    while(--t)
    {
        for(int i = 1; i <= t; i++)
        {
            // 用加法和模2运算替代相等判断
            a[t][i] = (a[t + 1][i] + a[t + 1][i + 1]) % 2;
            if(a[t][i])
                sum2++;
        }
    }
    // 检查总的1的数量是否等于总格子数的一半
    if(sum1 + sum2 == n * (n + 1) / 2 / 2)
        sum++;
}

// 生成第一行
void dfs(int x)
{
    for(int i = 0; i < 2; i++)
    {
        if(i)
            sum1++; // 如果放1，计数加1

        a[n][x] = i; // 放置当前位置

        if(x == n)
            check(); // 第一行生成完毕，检查
        else
            dfs(x + 1); // 继续生成下一位

        if(i)
            sum1--; // 回溯，减去计数
    }
}

int main()
{
    while(cin >> n && n)
    {
        cout << n << " ";
        // 如果总格子数是奇数，不可能有解
        if((n * (n + 1) / 2) % 2)
        {
            cout << "0" << endl;
            continue;
        }
        dfs(1);
        cout << sum << endl;
        sum = sum1 = 0; // 重置计数器
    }
    return 0;
}
