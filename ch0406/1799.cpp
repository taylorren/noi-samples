/*
算法：字符串处理 + 哈希表
难度：★★★☆☆ (3星)
描述：查找字符串的最短唯一前缀
算法分析：
1. 使用哈希表统计所有前缀的出现次数
2. 对每个单词查找最短的唯一前缀
3. 时间复杂度：O(N*L)，其中L是单词的平均长度
*/

#include <bits/stdc++.h>
using namespace std;

// 查找所有单词的唯一前缀
vector<string> findUniquePrefixes(const vector<string>& words) {
    unordered_map<string, int> prefixCount; // 存储前缀出现的次数

    // 计算每个前缀的出现次数
    for (const string& word : words) {
        string prefix = "";
        for (char ch : word) {
            prefix += ch; // 生成前缀
            prefixCount[prefix]++; // 更新前缀计数
        }
    }

    vector<string> result;
    // 查找每个单词的唯一前缀
    for (const string& word : words) {
        string prefix = "";
        string uniquePrefix = ""; // 存储唯一前缀
        for (char ch : word) {
            prefix += ch; // 生成前缀
            if (prefixCount[prefix] == 1) { // 如果前缀唯一
                uniquePrefix = prefix; // 记录唯一前缀
                break; // 找到唯一前缀，退出循环
            }
        }
        // 如果没有找到唯一前缀，使用整个单词
        if (uniquePrefix.empty()) {
            uniquePrefix = word;
        }
        result.push_back(word + " " + uniquePrefix); // 存储结果
    }
    return result;
}

int main() {
    vector<string> inputWords;
    string word;
    while (cin >> word) { // 从标准输入读取单词
        inputWords.push_back(word);
    }
    
    vector<string> output = findUniquePrefixes(inputWords); // 查找唯一前缀
    for (const string& line : output) {
        cout << line << endl; // 输出结果
    }

    return 0;
}