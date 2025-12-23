#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    bool is = true;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            is = false;
            break;
        }
    }
    return is;
}

int reverse(int n)
{
    int res = 0;
    while (n > 0)
    {
        int digit = n % 10;
        res = res * 10 + digit;
        n /= 10;
    }
    return res;
}

int main()
{
    ostringstream oss;

    int m, n;
    cin >> m >> n;

    for (int i = m; i <= n; i++)
    {
        int r = reverse(i);
        if (is_prime(i) && is_prime(r))
        {
            oss << i << ",";
        }
    }
    string res = oss.str();
    if (res.length() == 0)
    {
        cout << "No";
    }
    else
    {
        res.pop_back();
        cout << res;
    }
    return 0;
}
