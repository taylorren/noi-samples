#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int max = 0;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        int ssy, szy;
        cin >> ssy >> szy;
        if (ssy < 90 || ssy > 140)
        {
            count = 0;
            continue;
        }
        if (szy < 60 || szy > 90)
        {
            count = 0;
            continue;
        }
        count++;
        if (count > max)
        {
            max = count;
        }
    }

    cout << max << endl;
    return 0;
}
