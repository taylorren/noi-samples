#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> numbers(n);
    for(int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    double result = 0.0;
    if(n % 2 == 0)
    {
        result = numbers[n / 2 - 1] / 2.0 + numbers[n / 2] / 2.0;
    }
    else
    {
        result = numbers[n / 2];
    }

    cout << fixed << setprecision(1) << result << endl;
    return 0;
}