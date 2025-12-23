#include <iostream>
using namespace std;

int main()
{
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    
    // 存储每站人数变化
    int up[16] = {0};    // 上车人数
    int down[16] = {0};  // 下车人数
    int total[16] = {0}; // 每站开出后的人数
    
    // 第1站
    up[1] = a;
    down[1] = 0;
    total[1] = a;
    
    // 设第2站上下车人数为b
    int b = 1;  // 从1开始尝试
    bool found = false;
    
    while(!found)
    {
        // 重置数组
        for(int i = 2; i <= n; i++)
        {
            up[i] = down[i] = total[i] = 0;
        }
        
        // 第2站
        up[2] = down[2] = b;
        total[2] = total[1];  // 第2站上下车相同，人数不变
        
        // 从第3站开始计算
        for(int i = 3; i < n; i++)
        {
            up[i] = up[i-1] + up[i-2];  // 上车人数是前两站上车人数之和
            down[i] = up[i-1];          // 下车人数等于上一站上车人数
            total[i] = total[i-1] + up[i] - down[i];
        }
        
        // 最后一站
        down[n] = m;  // 给定的下车人数
        up[n] = 0;    // 最后一站不上车
        total[n] = total[n-1] - m;
        
        // 检查是否找到解
        if(total[n] == 0 && total[n-1] >= m)  // 确保最后一站能下够m个人
        {
            found = true;
        }
        else
        {
            b++;
        }
    }
    
    cout << total[x] << endl;
    return 0;
}