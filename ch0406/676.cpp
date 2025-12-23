/*
算法：图论（环检测）+ 贪心
难度：★★★☆☆ (3星)
描述：求将数组排序所需的最小交换次数
算法分析：
1. 将排序问题转化为图中的环检测
2. 贪心策略：每个环的最小交换次数是环大小减1
3. 使用visited数组避免重复访问
4. 时间复杂度：O(NlogN)
*/

#include <bits/stdc++.h>
using namespace std;

int minSwapsToSort(vector<int>& arr) {
    int n = arr.size();
    vector<bool> visited(n, false);
    vector<pair<int, int>> arrPos(n);

    // Store the original positions of the elements
    for (int i = 0; i < n; i++) {
        arrPos[i] = {arr[i], i}; // Pair of (value, original index)
    }

    // Sort the array by the first element (the values)
    sort(arrPos.begin(), arrPos.end());

    int swaps = 0;

    for (int i = 0; i < n; i++) {
        // If the element is already visited or is in the correct position
        if (visited[i] || arrPos[i].second == i) {
            continue;
        }

        // Find the size of the cycle
        int cycle_size = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;

            // Move to the next node in the cycle
            j = arrPos[j].second;
            cycle_size++;
        }

        // If there is a cycle of size cycle_size, we need (cycle_size - 1) swaps
        if (cycle_size > 0) {
            swaps += (cycle_size - 1);
        }
    }

    return swaps;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the permutation: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = minSwapsToSort(arr);
    cout << "Minimum number of swaps required: " << result << endl;

    return 0;
}