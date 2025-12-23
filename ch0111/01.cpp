#include <bits/stdc++.h>
using namespace std;

int numbers[100005];

int bin_search(int left, int right, int needle)
{
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        int mid_value = numbers[mid];
        if (mid_value == needle) // Exact match
        {
            return mid_value;
        }
        else
        {
            if (mid_value < needle)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    if (left == 0)
    {
        return numbers[left];
    }
    else
    {
        return abs(numbers[left] - needle) < abs(numbers[left - 1] - needle) ? numbers[left] : numbers[left - 1];
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int m;
    cin >> m;

    vector<int> found;
    for (int i = 1; i <= m; i++)
    {
        int needle;
        cin >> needle;
        found.push_back(bin_search(0, n - 1, needle));
    }

    for (auto &f : found)
    {
        cout << f << endl;
    }
    return 0;
}