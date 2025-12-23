/*
算法：数学方法
难度：★★☆☆☆ (2星)
描述：电池使用时间最大化问题
算法分析：
1. 关键发现：最大使用时间取决于两种情况
   - 如果最大电池 > 其他电池之和，返回其他电池之和
   - 否则返回总电量/2
2. 无需复杂的模拟或贪心
3. 时间复杂度：O(N)
*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double maximize_time(vector<int>& times) {
    int n = times.size();
    if (n < 2) return 0;
    
    // 找到最长寿命的电池
    int maxTime = 0;
    double sumOthers = 0;
    
    for (int time : times) {
        if (time > maxTime) {
            sumOthers += maxTime;
            maxTime = time;
        } else {
            sumOthers += time;
        }
    }
    
    // 两种情况：
    // 1. 最长寿命电池 > 其余电池寿命之和：答案是其余电池之和
    // 2. 最长寿命电池 <= 其余电池寿命之和：答案是总和/2
    if (maxTime > sumOthers) {
        return sumOthers;
    } else {
        return (sumOthers + maxTime) / 2;
    }
}

int main() {
    int N;
    while(cin >> N) {
        vector<int> batteryTimes(N);
        for(int i = 0; i < N; ++i) {
            cin >> batteryTimes[i];
        }
        cout << fixed << setprecision(1) << maximize_time(batteryTimes) << endl;
    }
    return 0;
}
