/*
算法：贪心 + 状态模拟
难度：★★★★☆ (4星)
描述：二进制密码锁状态转换问题
算法分析：
1. 贪心策略：从左到右依次考虑每个位置
2. 关键性质：每个按钮最多只需要按一次
3. 时间复杂度：O(2^n)，需要尝试第一个按钮的两种可能
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 按下按钮i，改变i和相邻位置的状态
void press(vector<int>& state, int pos, int n)
{
    state[pos] = 1 - state[pos]; // 改变当前位置
    if(pos > 0)
        state[pos - 1] = 1 - state[pos - 1]; // 改变左边
    if(pos < n - 1)
        state[pos + 1] = 1 - state[pos + 1]; // 改变右边
}

// 检查从start开始的解决方案
int solve(vector<int> current, const vector<int>& target, int n,
          bool pressFirst)
{
    int count = 0;
    vector<int> state = current;

    // 处理第一个按钮
    if(pressFirst)
    {
        press(state, 0, n);
        count++;
    }

    // 从第二个按钮开始，如果前一个位置不匹配，就按当前按钮
    for(int i = 1; i < n; i++)
    {
        if(state[i - 1] != target[i - 1])
        {
            press(state, i, n);
            count++;
        }
    }

    // 检查是否所有位置都匹配
    for(int i = 0; i < n; i++)
    {
        if(state[i] != target[i])
        {
            return -1; // 无法达到目标状态
        }
    }

    return count;
}

int main()
{
    string current, target;
    cin >> current >> target;

    int n = current.length();
    vector<int> curr(n), targ(n);

    // 转换输入为数字数组
    for(int i = 0; i < n; i++)
    {
        curr[i] = current[i] - '0';
        targ[i] = target[i] - '0';
    }

    // 尝试两种可能：按或不按第一个按钮
    int ans1 = solve(curr, targ, n, false);
    int ans2 = solve(curr, targ, n, true);

    // 找出最优解
    int result = -1;
    if(ans1 != -1 && ans2 != -1)
    {
        result = min(ans1, ans2);
    }
    else if(ans1 != -1)
    {
        result = ans1;
    }
    else if(ans2 != -1)
    {
        result = ans2;
    }

    if(result == -1)
    {
        cout << "impossible" << endl;
    }
    else
    {
        cout << result << endl;
    }

    return 0;
}