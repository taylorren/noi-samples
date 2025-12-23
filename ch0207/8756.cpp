#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    // 读取每种砝码的数量
    int a1, a2, a3, a4, a5, a6;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    
    // 砝码的重量
    int weights[6] = {1, 2, 3, 5, 10, 20};
    // 砝码的数量
    int counts[6] = {a1, a2, a3, a4, a5, a6};
    
    // 计算砝码总重量
    int total_weight = 0;
    for (int i = 0; i < 6; i++) {
        total_weight += weights[i] * counts[i];
    }
    
    // 使用布尔数组记录能称出的重量
    vector<bool> can_measure(total_weight + 1, false);
    can_measure[0] = true;  // 不放砝码可以称出0g
    
    // 对每种砝码进行处理
    for (int i = 0; i < 6; i++) {
        // 对于当前砝码，考虑使用0到counts[i]个
        for (int j = 1; j <= counts[i]; j++) {
            // 从大到小更新可称重量，避免重复计算
            for (int k = total_weight; k >= weights[i]; k--) {
                if (can_measure[k - weights[i]]) {
                    can_measure[k] = true;
                }
            }
        }
    }
    
    // 统计能称出的不同重量的个数（不包括0g）
    int count = 0;
    for (int i = 1; i <= total_weight; i++) {
        if (can_measure[i]) {
            count++;
        }
    }
    
    cout << "Total=" << count << endl;
    
    return 0;
}