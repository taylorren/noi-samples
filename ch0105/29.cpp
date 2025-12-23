#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long l;
    cin >> l;

    bool negative = false;
    if (l < 0)
    {
        negative = true;
        l = -l;
    }

    bool first_show = false;
    while (l > 0)
    {
        if (negative)
        {
            cout << "-";
            negative = false;
        }
        int d = l % 10;
        l = l / 10;
        if (d == 0)
        {
            if (first_show)
            {
                cout << d;
            }
            else
            {
                continue;
            }
        }
        else
        {
            first_show = true;
            cout << d;
        }
    }
    return 0;
}
