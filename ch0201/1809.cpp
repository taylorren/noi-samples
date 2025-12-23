#include <iostream>
#include <vector>
using namespace std;

int countDoublePairs(vector<int> &nums)
{
    int count = 0;

    // 遍历每一对数字
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            // 检查是否一个数是另一个数的两倍
            if (nums[i] * 2 == nums[j] || nums[j] * 2 == nums[i])
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    vector<int> nums;
    int num;

    // 读入数字直到遇到0
    while (cin >> num && num != 0)
    {
        nums.push_back(num);
    }

    cout << countDoublePairs(nums) << endl;

    return 0;
}
