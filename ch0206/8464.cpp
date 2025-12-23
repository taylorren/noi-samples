#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int maxProfit(const vector<int>& prices) {
    int buy1 = INT_MIN, sell1 = 0;
    int buy2 = INT_MIN, sell2 = 0;

    for (int price : prices) {
        buy1 = max(buy1, -price);              // 第一次买入
        sell1 = max(sell1, buy1 + price);      // 第一次卖出
        buy2 = max(buy2, sell1 - price);       // 第二次买入
        sell2 = max(sell2, buy2 + price);      // 第二次卖出
    }

    return sell2; // 返回最大利润
}

int main() {
    int T;
    cin >> T; // 读取测试组数
    while (T--) {
        int N;
        cin >> N; // 读取天数
        vector<int> prices(N);
        for (int i = 0; i < N; i++) {
            cin >> prices[i]; // 读取每天的价格
        }
        cout << maxProfit(prices) << endl; // 输出最大利润
    }
    return 0;
}