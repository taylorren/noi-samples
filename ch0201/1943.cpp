#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    for(int a = 1; a <= 100; a++)
    {
        for(int b = a; b <= 100; b++)
        { // b starts from a to avoid duplicates
            for(int c = 1; c <= 100; c++)
            {
                if(a * a + b * b == c * c)
                {
                    cout << a << "*" << a << " + " << b << "*" << b << " = "
                         << c << "*" << c << endl;
                }
            }
        }
    }
    return 0;
}