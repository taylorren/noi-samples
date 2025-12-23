#include <iostream>
#include <algorithm>
using namespace std;

// 检查某个选手的预测是否正确
bool is_prediction_correct(int p[], int player) {
    switch(player) {
        case 0: return p[4] == 1;     // A说E是第1名
        case 1: return p[1] == 2;     // B说B是第2名
        case 2: return p[0] == 5;     // C说A是第5名
        case 3: return p[2] != 1;     // D说C不是第1名
        case 4: return p[3] == 1;     // E说D是第1名
    }
    return false;
}

bool check_solution(int p[]) {
    // E不能是第2名或第3名
    if(p[4] == 2 || p[4] == 3) return false;
    
    // 检查每个选手的预测
    bool correct[5];
    int correct_count = 0;
    
    for(int i = 0; i < 5; i++) {
        correct[i] = is_prediction_correct(p, i);
        if(correct[i]) correct_count++;
    }
    
    // 必须恰好有两个预测正确
    if(correct_count != 2) return false;
    
    // 检查是否只有第1名和第2名的预测是正确的
    for(int i = 0; i < 5; i++) {
        if(correct[i] && p[i] > 2) return false;  // 如果预测正确但不是第1或2名
        if(!correct[i] && p[i] <= 2) return false; // 如果是第1或2名但预测错误
    }
    
    return true;
}

int main() {
    int p[5];
    for(int i = 0; i < 5; i++) p[i] = i + 1;
    
    do {
        if(check_solution(p)) {
            for(int i = 0; i < 5; i++) {
                cout << p[i] << endl;
            }
            return 0;
        }
    } while(next_permutation(p, p + 5));
    
    return 0;
}