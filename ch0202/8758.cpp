#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 将一个数转换为2的幂的表示形式
string convert(int n)
{
    if(n == 0)
        return "0";
    if(n == 1)
        return "2(0)";
    if(n == 2)
        return "2";

    // 找到最大的2的幂
    vector<int> powers;
    int num = n;
    int power = 0;

    while(num > 0)
    {
        if(num & 1)
        { // 如果当前位是1
            powers.push_back(power);
        }
        num >>= 1; // 右移一位
        power++;
    }

    // 构建结果字符串
    string result;
    for(int i = powers.size() - 1; i >= 0; i--)
    {
        if(i < powers.size() - 1)
        {
            result += "+";
        }

        if(powers[i] == 1)
        {
            result += "2";
        }
        else if(powers[i] == 0)
        {
            result += "2(0)";
        }
        else
        {
            result += "2(";
            result += convert(powers[i]);
            result += ")";
        }
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    cout << convert(n) << endl;
    return 0;
}