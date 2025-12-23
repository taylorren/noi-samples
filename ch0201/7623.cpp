#include <iostream>
#include <cstdlib>
using namespace std;

bool isValid(int len, int total) {
    return len > 0 && len < total;
}

int main() {
    int k, n1, n2, n3, n4, n5;
    cin >> k >> n1 >> n2 >> n3 >> n4 >> n5;
    
    // 将米转换为厘米
    k = k * 100;
    
    // 枚举井深（从1厘米到k厘米）
    for (int depth = 1; depth <= k; depth++) {
        // 从小到大枚举A的长度
        for (int a = 1; a < depth; a++) {
            // 根据方程1计算B: n1*A + B = depth
            int b = depth - n1 * a;
            if (!isValid(b, depth)) continue;
            
            // 根据方程2计算C: n2*B + C = depth
            int c = depth - n2 * b;
            if (!isValid(c, depth)) continue;
            
            // 根据方程3计算D: n3*C + D = depth
            int d = depth - n3 * c;
            if (!isValid(d, depth)) continue;
            
            // 根据方程4计算E: n4*D + E = depth
            int e = depth - n4 * d;
            if (!isValid(e, depth)) continue;
            
            // 验证方程5: n5*E + A = depth
            if (n5 * e + a != depth) continue;
            
            // 检查所有绳长是否各不相同
            if (a != b && a != c && a != d && a != e &&
                b != c && b != d && b != e &&
                c != d && c != e &&
                d != e) {
                cout << depth << " " << a << " " << b << " " 
                     << c << " " << d << " " << e << endl;
                return 0;
            }
        }
    }
    
    cout << "not found" << endl;
    return 0;
}