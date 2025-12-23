#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> charms(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> charms[i].first >> charms[i].second;
    }

    vector<int> dp(M + 1, 0);

    for(const auto& charm : charms)
    {
        int weight = charm.first;
        int desirability = charm.second;
        for(int j = M; j >= weight; --j)
        {
            dp[j] = max(dp[j], dp[j - weight] + desirability);
        }
    }

    int maxDesirability = *max_element(dp.begin(), dp.end());
    cout << maxDesirability << endl;

    return 0;
}