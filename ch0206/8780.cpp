#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> heights(N);
    for(int i = 0; i < N; i++)
    {
        cin >> heights[i];
    }

    vector<int> dp(N, 1); // 每个导弹至少可以拦截自己
    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(heights[j] >= heights[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl; // 输出最大拦截导弹数
    return 0;
}