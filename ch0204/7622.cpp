#include <iostream>
#include <vector>
using namespace std;

// 使用归并排序计算逆序对数量
long long merge_sort(vector<int>& arr, vector<int>& temp, int left, int right) {
    if(left >= right) return 0;

    int mid = (left + right) / 2;
    long long inv_count = 0;

    // 递归计算左右两半部分的逆序对数量
    inv_count += merge_sort(arr, temp, left, mid);
    inv_count += merge_sort(arr, temp, mid + 1, right);

    // 合并两个有序数组，同时统计跨越中点的逆序对
    int i = left;      // 左半部分起始位置
    int j = mid + 1;   // 右半部分起始位置
    int k = left;      // 临时数组的当前位置

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // 当右半部分的数小于左半部分的数时，形成逆序对
            // 左半部分从i到mid的所有数都会和arr[j]形成逆序对
            inv_count += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }

    // 处理剩余元素
    while(i <= mid) {
        temp[k++] = arr[i++];
    }
    while(j <= right) {
        temp[k++] = arr[j++];
    }

    // 将排序后的结果复制回原数组
    for(i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 读入排列
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 创建临时数组
    vector<int> temp(n);

    // 计算逆序对数量
    long long result = merge_sort(arr, temp, 0, n-1);

    cout << result << endl;

    return 0;
}