#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger {
private:
    vector<int> digits;  // 存储大数的每一位，个位在前
    bool isNegative;     // 符号位

public:
    // 构造函数
    BigInteger(long long num = 0) {
        isNegative = (num < 0);
        num = abs(num);
        if (num == 0) digits.push_back(0);
        while (num) {
            digits.push_back(num % 10);
            num /= 10;
        }
    }

    // 乘以整数
    BigInteger operator*(const int num) const {
        BigInteger result;
        result.digits.clear();
        int carry = 0;
        for (int i = 0; i < digits.size() || carry; i++) {
            long long curr = carry;
            if (i < digits.size()) curr += (long long)digits[i] * num;
            result.digits.push_back(curr % 10);
            carry = curr / 10;
        }
        while (result.digits.size() > 1 && result.digits.back() == 0)
            result.digits.pop_back();
        return result;
    }

    // 除以整数
    pair<BigInteger, int> divideByInt(const int num) const {
        BigInteger quotient;
        quotient.digits.clear();
        long long remainder = 0;
        vector<int> result;
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            remainder = remainder * 10 + digits[i];
            result.push_back(remainder / num);
            remainder %= num;
        }
        
        reverse(result.begin(), result.end());
        while (result.size() > 1 && result.back() == 0)
            result.pop_back();
            
        quotient.digits = result;
        return make_pair(quotient, remainder);
    }

    // 输出运算符重载
    friend ostream& operator<<(ostream& out, const BigInteger& num) {
        if (num.digits.empty()) {
            out << "0";
            return out;
        }
        if (num.isNegative) out << "-";
        for (int i = num.digits.size() - 1; i >= 0; i--)
            out << num.digits[i];
        return out;
    }
};

// 计算阶乘
BigInteger factorial(int n) {
    BigInteger result(1);
    for (int i = 2; i <= n; i++)
        result = result * i;
    return result;
}

int main() {
    int m, n;
    while (cin >> m >> n && (m || n)) {
        if (n > m) {
            cout << 0 << endl;
            continue;
        }
        
        // 计算(m+n)!*(m-n+1)/(m+1)
        BigInteger numerator = factorial(m + n);
        numerator = numerator * (m - n + 1);
        auto result = numerator.divideByInt(m + 1);
        
        cout << result.first << endl;
    }
    return 0;
}