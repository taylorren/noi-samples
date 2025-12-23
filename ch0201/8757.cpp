#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    do
    {
        // 构造三个三位数
        int num1 = nums[0] * 100 + nums[1] * 10 + nums[2];
        int num2 = nums[3] * 100 + nums[4] * 10 + nums[5];
        int num3 = nums[6] * 100 + nums[7] * 10 + nums[8];
        
        // 检查是否满足1:2:3的比例
        if(num2 == 2 * num1 && num3 == 3 * num1)
        {
            cout << num1 << " " << num2 << " " << num3 << endl;
        }
    } while(next_permutation(nums, nums + 9));
    
    return 0;
}