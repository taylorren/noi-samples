#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int left = 0, right = n - 1;
    bool found = false;

    while(left < right)
    {
        int sum = nums[left] + nums[right];
        if(sum == k)
        {
            found = true;
            break;
        }
        else if(sum < k)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << (found ? "yes" : "no") << endl;
    return 0;
}