#include <bits/stdc++.h>
using namespace std;

string multiply(string s, int n)
{
    int carry = 0;

    string res = "";
    int len = s.length();
    int tmp;
    for (int i = len - 1; i >= 0; i--)
    {
        int digit = s[i] - '0';
        tmp = digit * n + carry;

        if (tmp < 10)
        {
            res = to_string(tmp) + res;
            carry = 0;
        }
        else
        {
            res = to_string(tmp % 10) + res;
            carry = tmp/10;
        }
    }
    if (carry !=0)
    {
        res = to_string(carry / 10) + res;
    }

    return res;
}

int main()
{
    string number;
    cin >> number;
    int len = number.length();

    string hay = number + number;

    int cyclic_count = 0;
    for (int i = 1; i <= len; i++)
    {
        string res = multiply(number, i); // 高精度乘法
        //cout << i << ": |" << res << "|" << endl;
        if (hay.find(res, 0) == string::npos) // Not found
        {
            continue;
        }
        else
        {
            cyclic_count++;
        }
    }

    if (cyclic_count != len)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
    }

    return 0;
}
