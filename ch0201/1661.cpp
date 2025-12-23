#include <iostream>
using namespace std;

const int MAXN = 105;
bool possible[MAXN][MAXN];  // 记录每个位置是否可能

// 检查位置(x,y)是否在炸弹范围内
bool inRange(int x, int y, int bombX, int bombY, int P) {
    // 计算炸弹范围的边界
    int half = P / 2;
    int left = bombY - half;
    int right = bombY + half;
    int top = bombX - half;
    int bottom = bombX + half;
    
    return x >= top && x <= bottom && y >= left && y <= right;
}

int main() {
    int A, B, K;
    cin >> A >> B >> K;
    
    // 初始时所有位置都是可能的
    for(int i = 1; i <= A; i++) {
        for(int j = 1; j <= B; j++) {
            possible[i][j] = true;
        }
    }
    
    // 处理每个炸弹
    for(int k = 0; k < K; k++) {
        int R, S, P, T;
        cin >> R >> S >> P >> T;
        
        // 遍历所有位置
        for(int i = 1; i <= A; i++) {
            for(int j = 1; j <= B; j++) {
                if(!possible[i][j]) continue;  // 如果该位置已经被排除，跳过
                
                bool inBombRange = inRange(i, j, R, S, P);
                // 如果炸弹命中(T=1)但位置不在范围内，或炸弹未命中(T=0)但位置在范围内
                if((T == 1 && !inBombRange) || (T == 0 && inBombRange)) {
                    possible[i][j] = false;  // 排除该位置
                }
            }
        }
    }
    
    // 计算可能的位置数量
    int count = 0;
    for(int i = 1; i <= A; i++) {
        for(int j = 1; j <= B; j++) {
            if(possible[i][j]) count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}