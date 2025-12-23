//map

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    // 使用map来存储子串及其出现次数
    map<string, int> substrCount;
    
    // 枚举所有可能的子串
    int len = s.length();
    for(int i = 0; i < len; i++) {
        for(int j = 1; i + j <= len; j++) {
            string substr = s.substr(i, j);
            substrCount[substr]++;
        }
    }
    
    // 输出出现次数大于1的子串
    for(const auto& pair : substrCount) {
        if(pair.second > 1) {
            cout << pair.first << " " << pair.second << endl;
        }
    }
    
    return 0;
}