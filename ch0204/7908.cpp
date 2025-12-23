#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 只进行归并，不统计
void merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;      // 左半部分起始位置
    int j = mid + 1;   // 右半部分起始位置
    int k = left;      // 临时数组的当前位置
    
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    
    // 处理剩余元素
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];
    
    // 复制回原数组
    for(i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

// 归并排序
void merge_sort(vector<int>& arr, vector<int>& temp, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, temp, left, mid);
        merge_sort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

// 统计排序后数组中的数字频率
void count_numbers(const vector<int>& arr, vector<pair<int,int>>& counts) {
    if(arr.empty()) return;
    
    int current = arr[0];
    int count = 1;
    
    // 统计频率
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] == current) {
            count++;
        } else {
            counts.push_back({current, count});
            current = arr[i];
            count = 1;
        }
    }
    // 处理最后一个数字
    counts.push_back({current, count});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> temp(n);  // 归并排序用的临时数组
    vector<pair<int,int>> counts;  // 存储每个数字及其出现次数
    
    // 先排序
    merge_sort(arr, temp, 0, n-1);
    
    // 再统计（此时数组已经有序）
    count_numbers(arr, counts);
    
    // 输出结果（已经是有序的，不需要再排序）
    for(const auto& p : counts) {
        cout << p.first << " " << p.second << "\n";
    }
    
    return 0;
}