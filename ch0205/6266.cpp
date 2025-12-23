#include <bits/stdc++.h>
using namespace std;

bool canWin(int a, int b, int step) {
    // 如果a是b的2倍或以上，或者能整除，当前玩家赢
    if(a / b >= 2 || a % b == 0) 
        return step % 2 == 0;
        
    // 否则取完最大倍数后交换位置
    return canWin(b, a % b, step + 1);
}

int main() {
    int a, b;
    while(cin >> a >> b && a && b) {
        if(a < b) swap(a, b);
        
        // 如果一开始就是2倍或以上，直接赢
        if(a / b >= 2) {
            cout << "win" << endl;
            continue;
        }
        
        cout << (canWin(a, b, 0) ? "win" : "lose") << endl;
    }
    return 0;
}
