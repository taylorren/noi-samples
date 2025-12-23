#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    set<int> numbers;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        numbers.insert(tmp);
    }

    // stable_sort(numbers.begin(), numbers.end());

    cout << numbers.size() << endl;
    for (auto &e : numbers)
    {
        cout << e << " ";
    }

    return 0;
}
