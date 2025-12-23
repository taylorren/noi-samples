#include <iostream>

using namespace std;

int main()
{
    int m, k;
    cin >> m >> k;
    if (m % 19 == 0)
    {
        int count = 0;
        while (m > 0)
        {
            if (m % 10 == 3)
            {
                count++;
            }
            m /= 10;
        }
        if (count == k)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
