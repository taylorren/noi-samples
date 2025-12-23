#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int weight;
    char urgent;
    cin>>weight>>urgent;

    int cost=0;
    if(urgent=='y')
    {
        cost+=5;
    }
    if (weight<=1000)
    {
        cost+=8;
    }
    else 
    {
        cost+=ceil((weight-1000)/500.0)*4+8;
    }
    cout<<cost<<endl;


    return 0;
}
