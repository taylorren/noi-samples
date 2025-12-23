#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 高精度加法
string add(string a, string b) {
    string sum;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int x = i >= 0 ? a[i] - '0' : 0;
        int y = j >= 0 ? b[j] - '0' : 0;
        int s = x + y + carry;
        carry = s / 10;
        sum = char(s % 10 + '0') + sum;
        i--, j--;
    }
    return sum;
}

// 高精度乘法
string multiply(string a, string b) {
    vector<int> result(a.length() + b.length(), 0);
    
    for (int i = a.length() - 1; i >= 0; i--) {
        for (int j = b.length() - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + result[p2];
            
            result[p2] = sum % 10;
            result[p1] += sum / 10;
        }
    }
    
    string product;
    int i = 0;
    while (i < result.size() && result[i] == 0) i++;
    
    if (i == result.size()) return "0";
    
    while (i < result.size()) 
        product += result[i++] + '0';
    
    return product;
}

int main() {
    // f[i]表示2*i的方案数
    vector<string> f(251, "0");
    
    // 初始化
    f[0] = "1";  // 空走道只有一种方案
    f[1] = "1";  // 2*1只能放一个1*2
    f[2] = "3";  // 2*2有三种方案
    
    // 递推
    // f[i] = f[i-1] + 2*f[i-2]
    for(int i = 3; i <= 250; i++) {
        // f[i] = f[i-1] + 2*f[i-2]
        string doubled = add(f[i-2], f[i-2]);  // 2*f[i-2]
        f[i] = add(f[i-1], doubled);
    }
    
    int n;
    while(cin >> n) {
        cout << f[n] << endl;
    }
    
    return 0;
}