#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int k, i;
    double sum = 0;

    cin >> k;
    for (i = 1;; i++)
    {
        sum += 1.0 / i;
        if (sum > k)
            break;
    }

    cout<<i<<endl;
    return 0;
}
