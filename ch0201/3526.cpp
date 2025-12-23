#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 计算最大公约数
int gcd(int a, int b)
{
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;

    // 读入n个数
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // 先排序，这样只需要检查i之后的数作为分母
    sort(nums.begin(), nums.end());

    // 统计最简真分数的个数
    int count = 0;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            // nums[i] < nums[j]已经由排序保证，只需要检查是否互质
            if(gcd(nums[i], nums[j]) == 1)
            {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}