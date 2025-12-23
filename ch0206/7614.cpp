#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(N, vector<int>(N, 0));
    dp[0][0] = grid[0][0];

    // Initialize the first row
    for(int j = 1; j < N; ++j)
    {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Initialize the first column
    for(int i = 1; i < N; ++i)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill the dp table
    for(int i = 1; i < N; ++i)
    {
        for(int j = 1; j < N; ++j)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    cout << dp[N - 1][N - 1] << endl;

    return 0;
}