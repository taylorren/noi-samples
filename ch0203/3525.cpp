#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 预处理所有可能的台阶数（n <= 30）
    int f[31] = {1}; // f[0] = 1作为边界条件
    f[1] = 1;
    f[2] = 2;
    
    // 递推计算
    for(int i = 3; i <= 30; i++)
    {
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    }
    
    // 处理输入
    int n;
    while(cin >> n && n)
    {
        cout << f[n] << '\n';
    }
    
    return 0;
}