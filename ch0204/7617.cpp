#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 快速选择算法的分区函数
int partition(vector<int>& nums, int left, int right)
{
    int pivot = nums[right];
    int i = left - 1;

    for(int j = left; j < right; j++)
    {
        if(nums[j] >= pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[right]);
    return i + 1;
}

// 快速选择算法
void quickSelect(vector<int>& nums, int left, int right, int k)
{
    if(left >= right)
        return;

    int pos = partition(nums, left, right);
    int count = pos - left + 1;

    if(count == k)
    {
        return;
    }
    else if(count > k)
    {
        quickSelect(nums, left, pos - 1, k);
    }
    else
    {
        quickSelect(nums, pos + 1, right, k - count);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int& x : nums)
    {
        cin >> x;
    }

    int k;
    cin >> k;

    // 使用快速选择找到前k大的数
    quickSelect(nums, 0, n - 1, k);

    // 对前k个数排序
    sort(nums.begin(), nums.begin() + k, greater<int>());

    // 输出结果
    for(int i = 0; i < k; i++)
    {
        cout << nums[i] << endl;
    }

    return 0;
}