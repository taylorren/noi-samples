#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        // 如果元素少于4个，无解
        if (n < 4) {
            cout << "no solution" << endl;
            continue;
        }
        
        // 将所有元素存入集合，便于快速查找
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // 按降序排序，优先考虑较大的d值
        sort(nums.begin(), nums.end(), greater<int>());
        
        bool found = false;
        
        // 枚举所有可能的三元组(a,b,c)
        for (int i = 0; i < n && !found; i++) {
            int d = nums[i];
            
            for (int j = 0; j < n; j++) {
                if (j == i) continue; // a不能等于d
                int a = nums[j];
                
                for (int k = j + 1; k < n && !found; k++) {
                    if (k == i) continue; // b不能等于d
                    int b = nums[k];
                    
                    // 计算c = d - a - b
                    int c = d - a - b;
                    
                    // 检查c是否在集合中，且不等于a,b,d
                    if (c != a && c != b && c != d && numSet.count(c)) {
                        cout << d << endl;
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
        }
        
        if (!found) {
            cout << "no solution" << endl;
        }
    }
    
    return 0;
}