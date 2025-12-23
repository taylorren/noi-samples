#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 检查方程是否成立
bool checkEquation(int v, int w, int x, int y, int z, int target) {
    long long result = 
        1LL * v -
        1LL * w * w +
        1LL * x * x * x -
        1LL * y * y * y * y +
        1LL * z * z * z * z * z;
    return result == target;
}

// 从字符串生成5个字母的组合并检查
string findCombination(const string& letters, int target) {
    int n = letters.length();
    if(n < 5) return "";
    
    // 创建一个包含n个数的数组，其中前5个为1，表示选中
    vector<bool> v(n);
    fill(v.begin(), v.begin() + 5, true);
    
    string best;
    // 生成所有5个字母的组合
    do {
        string curr;
        for(int i = 0; i < n; i++) {
            if(v[i]) curr += letters[i];
        }
        
        // 对这5个字母生成所有排列
        sort(curr.begin(), curr.end());
        do {
            int v = curr[0] - 'A' + 1;
            int w = curr[1] - 'A' + 1;
            int x = curr[2] - 'A' + 1;
            int y = curr[3] - 'A' + 1;
            int z = curr[4] - 'A' + 1;
            
            if(checkEquation(v, w, x, y, z, target)) {
                if(best.empty() || curr > best) {
                    best = curr;
                }
            }
        } while(next_permutation(curr.begin(), curr.end()));
        
    } while(prev_permutation(v.begin(), v.end()));
    
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int target;
    string letters;
    
    while(cin >> target >> letters) {
        if(target == 0 && letters == "END") break;
        
        string result = findCombination(letters, target);
        if(result.empty()) {
            cout << "no solution\n";
        } else {
            cout << result << '\n';
        }
    }
    
    return 0;
}