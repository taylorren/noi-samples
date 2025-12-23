#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    if(N == 1)
    {
        cout << A[0] << endl;
        return 0;
    }
    if(N == 2)
    {
        cout << A[0] + A[1] << endl;
        return 0;
    }

    vector<int> dp(N);
    dp[0] = A[0];
    dp[1] = A[0] + A[1];
    dp[2] = max(A[0] + A[1], max(A[0] + A[2], A[1] + A[2]));

    for(int i = 3; i < N; ++i)
    {
        dp[i] =
            max(dp[i - 1], max(dp[i - 2] + A[i], dp[i - 3] + A[i] + A[i - 1]));
    }

    cout << dp[N - 1] << endl;

    return 0;
}