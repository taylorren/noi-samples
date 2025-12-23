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

int main()
{
    int n, count = 0;
    int p1, p2;

    cin >> n;

    p1 = 3;
    for (int i = 3; i <= n; i++)
    {
        if (is_prime(i))
        {
            p2 = i;
            if (p2 - p1 == 2)
            {
                cout << p1 << " " << p2 << endl;
                count++;
            }
        }
        p1 = p2;
    }
    if (count == 0)
    {
        cout << "empty" << endl;
    }

    return 0;
}
