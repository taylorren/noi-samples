#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n;

    vector<int> numbers;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }

    cin >> m;

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < n; i++)
    {
        int needle = m - numbers[i];
        int s = i + 1, e = n - 1;

        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (numbers[mid] == needle)
            {
                cout << numbers[i] << " " << needle << endl;
                return 0;
            }
            else if (numbers[mid] > needle)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
