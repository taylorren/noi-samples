#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 将字符串形式的大数转换为二进制数组
vector<int> toBinary(string n)
{
    vector<int> binary;
    int carry = 0;

    // 不断除以2，得到二进制表示
    while(!n.empty())
    {
        int len = n.length();
        string newNum;
        carry = 0;

        for(int i = 0; i < len; i++)
        {
            int current = carry * 10 + (n[i] - '0');
            carry = current % 2;
            if(i > 0 || current / 2 > 0)
                newNum += (current / 2) + '0';
        }

        binary.push_back(carry);
        n = newNum;
    }

    return binary;
}

// 分治法实现快速幂
int fastPow(vector<int>& binary)
{
    const int MOD = 10000;
    long long result = 1;
    long long base = 2011;

    // 根据二进制位计算结果
    for(int i = 0; i < binary.size(); i++)
    {
        if(binary[i] == 1)
        {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
    }

    return result;
}

int main()
{
    int k;
    cin >> k;

    while(k--)
    {
        string n;
        cin >> n;
        // 将输入转换为二进制
        vector<int> binary = toBinary(n);
        // 使用分治法计算结果
        cout << fastPow(binary) << endl;
    }

    return 0;
}