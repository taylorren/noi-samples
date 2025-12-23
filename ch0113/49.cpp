#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 高精度乘法
string multiply(string num1, string num2)
{
    int len1 = num1.length();
    int len2 = num2.length();
    vector<int> result(len1 + len2, 0);

    // 从右向左遍历
    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = result[i + j + 1] + mul;

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    // 转换为字符串
    string s;
    int i = 0;
    while (i < result.size() && result[i] == 0)
        i++;

    if (i == result.size())
        return "0";

    while (i < result.size())
    {
        s += result[i] + '0';
        i++;
    }

    return s;
}

// 比较两个大数
bool isLessOrEqual(string num1, string num2)
{
    if (num1.length() != num2.length())
        return num1.length() < num2.length();
    return num1 <= num2;
}

// 计算 a 的 n 次方
string power(string a, int n)
{
    if (n == 0)
        return "1";
    string result = a;
    for (int i = 1; i < n; i++)
    {
        result = multiply(result, a);
    }
    return result;
}

int main()
{
    string a, b;
    cin >> a >> b;

    // 从0开始尝试，直到找到合适的x
    for (int x = 0; x <= 20; x++)
    {
        string current = power(a, x);
        string next = power(a, x + 1);

        // 如果 a^x <= b < a^(x+1)，找到答案
        if (isLessOrEqual(current, b) && !isLessOrEqual(next, b))
        {
            cout << x << endl;
            break;
        }
    }

    return 0;
}