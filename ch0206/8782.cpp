#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    string num;
    cin >> num;

    vector<vector<long long>> dp(N + 1, vector<long long>(K + 1, 0));

    // Precompute the integer values of all substrings
    vector<vector<long long>> value(N + 1, vector<long long>(N + 1, 0));
    for(int i = 0; i < N; ++i)
    {
        long long val = 0;
        for(int j = i; j < N; ++j)
        {
            val = val * 10 + (num[j] - '0');
            value[i + 1][j + 1] = val;
        }
    }

    // Initialize dp for the case with 0 multiplication signs
    for(int i = 1; i <= N; ++i)
    {
        dp[i][0] = value[1][i];
    }

    // Fill dp table
    for(int j = 1; j <= K; ++j)
    {
        for(int i = j + 1; i <= N; ++i)
        {
            for(int k = j; k < i; ++k)
            {
                dp[i][j] = max(dp[i][j], dp[k][j - 1] * value[k + 1][i]);
            }
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}