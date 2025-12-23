#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, hundred, ten, digit, count = 0, ans;
    cin >> n;

    for (int i = 10; i <= 30; i++)
    {
        ans = i * i;
        hundred = ans / 100;
        ten = ans % 100 / 10;
        digit = ans % 10;
        if (hundred != ten && hundred != digit && ten != digit)
        {
            continue;
        }
        count++;
        if (count == n)
        {
            break;
        }
    }
    cout << ans << endl;

    return 0;
}