#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    // 找出n所在的对角线
    // 第k条对角线有k个数
    // 前k条对角线共有k*(k+1)/2个数
    int k = 1;
    while(k * (k + 1) / 2 < n)
    {
        k++;
    }
    
    // 计算n在当前对角线上的位置
    int pos = n - (k - 1) * k / 2;
    
    // k是对角线的序号（从1开始）
    // pos是在当前对角线上的位置（从1开始）
    
    int numerator, denominator;
    
    // 根据k的奇偶性确定方向
    if(k % 2 == 0)
    {
        // 偶数对角线：从左下到右上
        numerator = pos;
        denominator = k - pos + 1;
    }
    else
    {
        // 奇数对角线：从右上到左下
        numerator = k - pos + 1;
        denominator = pos;
    }
    
    cout << numerator << "/" << denominator << endl;
    
    return 0;
}