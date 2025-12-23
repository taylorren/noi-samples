/*
算法：贪心算法 + 单调栈
难度：★★★★☆ (4星)
描述：删除k个数字后得到最小数
算法分析：
1. 贪心策略：从左到右遍历，删除比后面数字大的数字
2. 使用单调栈维护递增序列
3. 处理前导零和剩余删除次数
4. 时间复杂度：O(N)
*/

#include <bits/stdc++.h>

using namespace std;

// 函数：从数字中删除 k 位以生成最小的整数
string getMinNumberAfterDeletion(const string &num, int k)
{
    stack<char> s;
    int n = num.size();

    for (int i = 0; i < n; i++)
    {
        // 当栈不为空，且可以删除数字，且当前数字小于栈顶数字时，弹出栈顶数字
        while (!s.empty() && k > 0 && s.top() > num[i])
        {
            s.pop();
            k--;
        }
        s.push(num[i]);
    }

    // 如果还有剩余的数字需要删除，从栈顶开始删除
    while (k > 0 && !s.empty())
    {
        s.pop();
        k--;
    }

    // 从栈中构建结果
    string result;
    while (!s.empty())
    {
        result += s.top();
        s.pop();
    }

    // 反转结果，因为我们是从栈中构建的
    reverse(result.begin(), result.end());

    // 去掉前导零（如果有的话）
    while (result.size() > 1 && result[0] == '0')
    {
        result.erase(result.begin());
    }

    return result;
}

int main()
{
    int T; // 输入的测试用例数量
    cin >> T;

    while (T--)
    {
        string n;
        int k;

        // 读取数字和要删除的位数
        cin >> n >> k;

        // 获取删除 k 位后的最小数字
        string minNumber = getMinNumberAfterDeletion(n, k);

        // 输出结果
        cout << minNumber << endl;
    }

    return 0;
}