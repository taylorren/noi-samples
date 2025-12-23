#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count[6];  // 每种砝码的数量
    int weight[6] = {1, 2, 3, 5, 10, 20};  // 砝码的重量
    set<int> weights;  // 用来存储所有可能的重量
    
    // 读入每种砝码的数量
    for(int i = 0; i < 6; i++)
    {
        cin >> count[i];
    }
    
    // 枚举第一种砝码(1g)的使用数量
    for(int a = 0; a <= count[0]; a++)
    {
        // 枚举第二种砝码(2g)的使用数量
        for(int b = 0; b <= count[1]; b++)
        {
            // 枚举第三种砝码(3g)的使用数量
            for(int c = 0; c <= count[2]; c++)
            {
                // 枚举第四种砝码(5g)的使用数量
                for(int d = 0; d <= count[3]; d++)
                {
                    // 枚举第五种砝码(10g)的使用数量
                    for(int e = 0; e <= count[4]; e++)
                    {
                        // 枚举第六种砝码(20g)的使用数量
                        for(int f = 0; f <= count[5]; f++)
                        {
                            // 计算当前组合的总重量
                            int sum = a*weight[0] + b*weight[1] + c*weight[2] + 
                                    d*weight[3] + e*weight[4] + f*weight[5];
                            // 如果至少使用了一个砝码，则记录这个重量
                            if(sum > 0)
                            {
                                weights.insert(sum);
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << "Total=" << weights.size() << endl;
    return 0;
}