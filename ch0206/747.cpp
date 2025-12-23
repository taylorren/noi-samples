#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> sequence(N);
    for (int i = 0; i < N; ++i) {
        cin >> sequence[i];
    }

    // Initialize dp vector
    vector<bool> dp(K, false);
    dp[0] = true;

    for (int i = 0; i < N; ++i) {
        vector<bool> new_dp(K, false);
        for (int j = 0; j < K; ++j) {
            if (dp[j]) {
                new_dp[(j + sequence[i] % K + K) % K] = true;
                new_dp[(j - sequence[i] % K + K) % K] = true;
            }
        }
        dp = new_dp;
    }

    if (dp[0]) {
        cout << "Divisible" << endl;
    } else {
        cout << "Not divisible" << endl;
    }

    return 0;
}