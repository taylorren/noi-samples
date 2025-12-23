#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int K;
    cin >> K;
    
    vector<int> nums(K);
    for (int i = 0; i < K; i++) {
        cin >> nums[i];
    }

    // Sort in descending order for greedy distribution
    sort(nums.rbegin(), nums.rend());

    // Maximum value M as reference
    int M = nums[0];
    
    int bestN = 1;
    long long minTotalDeviation = LLONG_MAX;

    // Try different numbers of sets from 1 to K
    for (int N = 1; N <= K; N++) {
        // Use priority queue (min-heap) for efficient distribution
        priority_queue<long long, vector<long long>, greater<long long>> loads;
        
        // Initialize N sets with 0 load
        for (int i = 0; i < N; i++) {
            loads.push(0);
        }

        // Distribute numbers greedily to set with minimum load
        for (int num : nums) {
            long long minLoad = loads.top();
            loads.pop();
            loads.push(minLoad + num);
        }

        // Calculate total deviation
        long long totalDeviation = 0;
        while (!loads.empty()) {
            totalDeviation += abs(loads.top() - M);
            loads.pop();
        }

        // Update best solution
        if (totalDeviation < minTotalDeviation) {
            minTotalDeviation = totalDeviation;
            bestN = N;
        }
    }

    cout << bestN << endl;
    return 0;
}
