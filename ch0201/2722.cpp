#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int& num : nums)
    {
        cin >> num;
    }

    int count = 0;
    // 检查每个数是否可以由其他两个数的和得到
    for(int i = 0; i < n; i++)
    {
        bool found = false;
        // 尝试所有可能的两数组合
        for(int j = 0; j < n; j++)
        {
            for(int j = 0; j < n && !found; j++)
            {
                if(j == i)
                    continue; // 跳过自身
                for(int k = j + 1; k < n && !found; k++)
                {
                    if(k == i)
                        continue; // 跳过自身
                    if(nums[j] + nums[k] == nums[i])
                    {
                        found = true;
                        count++;
                    }
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}