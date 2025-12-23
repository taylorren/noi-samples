#include <iostream>
using namespace std;

// 扩展欧几里得算法求逆元
long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

// 求解模线性方程组
long long chinese_remainder(long long r[], long long m[], int n) {
    long long M = 1;
    for (int i = 0; i < n; i++) {
        M *= m[i];
    }
    
    long long result = 0;
    for (int i = 0; i < n; i++) {
        long long Mi = M / m[i];
        long long x, y;
        exgcd(Mi, m[i], x, y);
        result = (result + r[i] * Mi * x) % M;
    }
    
    return (result % M + M) % M;
}

int main() {
    long long p, e, i, d;
    cin >> p >> e >> i >> d;
    
    // 将时间调整为相对于d的余数
    p = (p - d % 23 + 23) % 23;
    e = (e - d % 28 + 28) % 28;
    i = (i - d % 33 + 33) % 33;
    
    // 设置模数数组和余数数组
    long long m[] = {23, 28, 33};
    long long r[] = {p, e, i};
    
    // 使用中国剩余定理求解
    long long result = chinese_remainder(r, m, 3);
    
    // 如果结果为0，需要加上一个周期
    if (result == 0) {
        result = 23 * 28 * 33;
    }
    
    cout << result << endl;
    
    return 0;
}