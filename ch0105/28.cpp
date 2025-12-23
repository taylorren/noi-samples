#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long l;
    cin>>l;

    while(l>0)
    {
        int d=l%10;
        l=l/10;
        cout<<d<<" ";
    }
    return 0;
}
