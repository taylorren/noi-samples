#include <iostream>
#include <iomanip>
using namespace std;

int contains(int i, int digit)
{
    int count = 0;
    while (i > 0)
    {
        if (i % 10 == digit)
        {
            count++;
        }
        i /= 10;
    }
    return count;
}

int main()
{
    int max;
    cin >> max;
    int sum = 0;

    for (int i = 1; i <= max; i++)
    {
        sum += contains(i, 1);
    }
    cout << sum << endl;
    return 0;
}
