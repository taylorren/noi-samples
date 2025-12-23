#include <iostream>
#include <vector>
using namespace std;

// 获取一个数的所有因子
vector<int> getFactors(int n) {
    vector<int> factors;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
        }
    }
    return factors;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> factors = getFactors(N);
    int result = -1;
    
    // 遍历所有因子
    for (int a : factors) {
        int b = M - a;
        // 检查a是否为正数且M-a是否也是N的因子
        if (a > 0 && b > 0 && N % b == 0) {
            result = a;
            break;  // 找到第一个符合条件的就是最小的
        }
    }
    
    cout << result << endl;
    return 0;
}
