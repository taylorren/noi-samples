#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string input;
    getline(cin, input); // 读取输入字符串

    vector<int> numbers; // 存储提取的整数
    string current_number; // 当前数字串

    for (char ch : input) {
        if (isdigit(ch)) {
            current_number += ch; // 如果是数字，添加到当前数字串
        } else {
            if (!current_number.empty()) {
                numbers.push_back(stoi(current_number)); // 将当前数字串转换为整数并存储
                current_number.clear(); // 清空当前数字串
            }
        }
    }

    // 处理最后一个数字串（如果存在）
    if (!current_number.empty()) {
        numbers.push_back(stoi(current_number));
    }

    // 如果没有提取到数字，输出0
    if (numbers.empty()) {
        cout << 0 << endl;
        return 0;
    }

    // 排序
    sort(numbers.begin(), numbers.end());

    // 输出结果
    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << numbers[i];
        if (i < numbers.size() - 1) {
            cout << ","; // 逗号分隔
        }
    }
    cout << endl;

    return 0;
}
