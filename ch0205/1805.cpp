#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

// 存储所有可能的切割方案
vector<vector<string>> solutions;
int target;
string paper;

// 将字符串转换为数字
inline int strToNum(const string& s) {
    int num = 0;
    for(char c : s) {
        num = num * 10 + (c - '0');
    }
    return num;
}

// 计算一个方案的总和
int calcSum(const vector<string>& parts) {
    int sum = 0;
    for(const string& s : parts) {
        sum += strToNum(s);
    }
    return sum;
}

// 递归尝试所有切割方案
void solve(int pos, int sum, vector<string>& parts) {
    if(sum > target) return;  // 剪枝：和已经超过目标
    if(pos == paper.length()) {
        if(sum <= target) {
            solutions.push_back(parts);
        }
        return;
    }
    
    // 尝试切割不同长度的数字
    for(int len = 1; len <= paper.length()-pos && len <= 6; len++) {
        string num_str = paper.substr(pos, len);
        int num = strToNum(num_str);
        
        // 如果这个切片合法（不超过最大长度且和不会超过目标）
        if(sum + num <= target) {
            parts.push_back(num_str);
            solve(pos+len, sum+num, parts);
            parts.pop_back();
        }
    }
}

int main() {
    while(true) {
        cin >> target >> paper;
        if(target == 0 && paper == "0") break;
        
        // 特殊情况：输入数字等于目标数
        int paper_num = strToNum(paper);
        if(paper_num == target) {
            cout << target << " " << target << endl;
            continue;
        }
        
        // 清空上一次的解
        solutions.clear();
        vector<string> parts;
        solve(0, 0, parts);
        
        // 没有解
        if(solutions.empty()) {
            cout << "error" << endl;
            continue;
        }
        
        // 找出最大和
        int maxSum = 0;
        for(const auto& sol : solutions) {
            int sum = calcSum(sol);
            if(sum <= target) {
                maxSum = max(maxSum, sum);
            }
        }
        
        // 统计达到最大和的方案数
        vector<vector<string>> bestSols;
        for(const auto& sol : solutions) {
            if(calcSum(sol) == maxSum) {
                bestSols.push_back(sol);
            }
        }
        
        // 如果有多个最优解
        if(bestSols.size() > 1) {
            cout << "rejected" << endl;
            continue;
        }
        
        // 输出唯一的最优解
        cout << maxSum;
        for(const string& num_str : bestSols[0]) {
            cout << " " << strToNum(num_str);
        }
        cout << endl;
    }
    return 0;
}