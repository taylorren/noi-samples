#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double const PI=3.14159;

    double r;
    cin>>r;
    cout<<fixed<<setprecision(4)<<2*r<<" ";
    cout<<fixed<<setprecision(4)<<2*r*PI<<" ";
    cout<<fixed<<setprecision(4)<<r*r*PI<<endl;
    return 0;
}
