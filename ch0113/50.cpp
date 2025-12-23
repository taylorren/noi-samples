#include <bits/stdc++.h>
using namespace std;

int digital_root(const std::string& num) {
    vector<int> digits;

    // 将每个字符转换为数字并存入数组
    for (char ch : num) {
        digits.push_back(ch - '0');
    }

    // 计算数根
    while (digits.size() > 1) {
        int sum = 0;
        for (int digit : digits) {
            sum += digit;  // 将各位数字相加
        }
        digits.clear();  // 清空数组以存放新的数字
        while (sum > 0) {
            digits.push_back(sum % 10);  // 将和的各位数字存入数组
            sum /= 10;
        }
    }

    return digits[0];  // 返回最终的一位数
}

int main() {
    string number;
    std::cin >> number;

    int result = digital_root(number);
    cout <<  result << std::endl;

    return 0;
}
