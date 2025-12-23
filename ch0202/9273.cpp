#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 高精度整数类
class BigInt
{
    vector<int> digits; // 存储每一位数字，个位在前

  public:
    // 默认构造函数
    BigInt() {}
    
    // 从整数构造
    BigInt(int n)
    {
        if(n == 0) {
            digits.push_back(0);
            return;
        }
        while(n > 0)
        {
            digits.push_back(n % 10);
            n /= 10;
        }
    }

    bool empty() const {
        return digits.empty();
    }

    BigInt operator+(const BigInt& other) const
    {
        BigInt result;
        int carry = 0;
        size_t i = 0;

        while(i < digits.size() || i < other.digits.size() || carry)
        {
            int sum = carry;
            if(i < digits.size())
                sum += digits[i];
            if(i < other.digits.size())
                sum += other.digits[i];

            result.digits.push_back(sum % 10);
            carry = sum / 10;
            i++;
        }

        return result;
    }

    friend ostream& operator<<(ostream& out, const BigInt& n)
    {
        if(n.digits.empty()) {
            out << "0";
            return out;
        }
        for(int i = n.digits.size() - 1; i >= 0; i--)
        {
            out << n.digits[i];
        }
        return out;
    }
};

// 记忆化数组
vector<BigInt> memo;

// 递归计算铺砖方案数
BigInt solve(int n)
{
    if(n == 0)
        return BigInt(1);
    if(n == 1)
        return BigInt(1);
    if(n == 2)
        return BigInt(3);

    // 如果已经计算过，直接返回结果
    if(n < memo.size() && !memo[n].empty())
    {
        return memo[n];
    }

    // 扩展记忆化数组大小
    if(n >= memo.size())
    {
        memo.resize(n + 1);
    }

    // 递归计算
    // f(n) = f(n-1) + 2*f(n-2)
    memo[n] = solve(n - 1) + solve(n - 2) + solve(n - 2);
    return memo[n];
}

int main()
{
    int n;
    // 初始化记忆化数组
    memo.resize(251); // 因为n最大为250

    while(cin >> n)
    {
        cout << solve(n) << endl;
    }
    return 0;
}