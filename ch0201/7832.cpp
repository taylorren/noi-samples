#include <iostream>
using namespace std;

// 计算最大公约数
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    
    // 存储最大分数的分子和分母
    int maxNumerator = 0;
    int maxDenominator = 1;
    
    // 遍历所有可能的分母
    for(int den = 1; den <= n; den++)
    {
        // 对于每个分母，找出使得分数小于a/b的最大分子
        // num/den < a/b => num*b < den*a
        int num = (den * a - 1) / b;
        
        // 确保分子是正数
        if(num <= 0)
        {
            continue;
        }
        
        // 如果分数不是最简的，跳过
        if(gcd(num, den) != 1)
        {
            continue;
        }
        
        // 如果当前分数大于之前找到的最大分数，更新结果
        if(num * maxDenominator > den * maxNumerator)
        {
            maxNumerator = num;
            maxDenominator = den;
        }
    }
    
    cout << maxNumerator << " " << maxDenominator << endl;
    return 0;
}