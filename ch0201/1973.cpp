#include <iostream>
using namespace std;

// 将指定进制的数转换为十进制
long long to_decimal(long long num, int base) {
    long long result = 0;
    long long power = 1;
    
    while (num > 0) {
        int digit = num % 10;
        // 检查数字是否合法（小于进制基数）
        if (digit >= base) return -1;
        result += digit * power;
        power *= base;
        num /= 10;
    }
    return result;
}

int main() {
    long long p, q, r;
    cin >> p >> q >> r;
    
    // 尝试每个可能的进制（2-16）
    for (int base = 2; base <= 16; base++) {
        // 将p和q转换为十进制
        long long p_dec = to_decimal(p, base);
        long long q_dec = to_decimal(q, base);
        long long r_dec = to_decimal(r, base);
        
        // 检查转换是否有效
        if (p_dec != -1 && q_dec != -1 && r_dec != -1) {
            // 检查乘法等式是否成立
            if (p_dec * q_dec == r_dec) {
                cout << base << endl;
                return 0;
            }
        }
    }
    
    // 如果没有找到合适的进制
    cout << 0 << endl;
    return 0;
}