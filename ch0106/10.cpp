#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 函数：高精度加法
vector<int> highPrecisionAdd(const string &num1, const string &num2)
{
    vector<int> result;      // 存储结果
    int carry = 0;           // 进位
    int i = num1.size() - 1; // num1 的最后一位索引
    int j = num2.size() - 1; // num2 的最后一位索引

    // 从后向前逐位相加
    while (i >= 0 || j >= 0 || carry)
    {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0; // num1 的当前位
        int digit2 = (j >= 0) ? num2[j] - '0' : 0; // num2 的当前位

        int sum = digit1 + digit2 + carry; // 计算当前位的和
        carry = sum / 10;
        result.push_back(sum % 10);

        i--; // 移动到 num1 的前一位
        j--; // 移动到 num2 的前一位
    }

    // 结果是反向存储的，需要反转
    reverse(result.begin(), result.end());

    return result;
}

// 函数：将结果转换为字符串
string vectorToString(const vector<int> &vec)
{
    string result;
    bool output = false;
    for (int digit : vec)
    {
        if (digit == 0 && !output)
        {
            continue;
        }
        else
        {
            result += to_string(digit);
            output = true;
        }
    }

    return result.empty() ? "0" : result;
}

int main()
{
    string num1, num2;
    cin >> num1; // 输入第一个大数
    cin >> num2; // 输入第二个大数

    // 进行高精度加法
    vector<int> result = highPrecisionAdd(num1, num2);

    // 输出结果
    cout << vectorToString(result) << endl;

    return 0;
}