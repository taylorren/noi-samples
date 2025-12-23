#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 100005;
int primes[MAXN]; // 存储素数
int primeCount = 0; // 素数个数

// 预处理所有素数
void generatePrimes() {
    bool isComposite[MAXN] = {false}; // false表示可能是素数，true表示是合数
    
    for (int i = 2; i < MAXN; i++) {
        if (!isComposite[i]) {
            primes[primeCount++] = i; // i是素数，加入数组
            
            // 标记i的所有倍数为合数
            for (int j = i + i; j < MAXN; j += i) {
                isComposite[j] = true;
            }
        }
    }
}

int main() {
    generatePrimes();
    int m, a, b;
    
    while (cin >> m >> a >> b && (m != 0 || a != 0 || b != 0)) {
        int p = 0, q = 0;
        double x = 1.0 * a / b;
        
        for (int i = 0; i < primeCount; i++) {
            if (primes[i] > m) {
                break;
            }
            
            for (int j = i; j < primeCount; j++) {
                double y = 1.0 * primes[i] / primes[j];
                if ((long long)primes[i] * primes[j] > m || y < x) {
                    break;
                }
                
                if ((long long)primes[i] * primes[j] > (long long)p * q) {
                    p = primes[i];
                    q = primes[j];
                }
            }
        }
        
        cout << p << " " << q << endl;
    }
    
    return 0;
}