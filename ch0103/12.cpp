#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main()
{
    const double PI=3.14;
    double r;
    cin>>r;

    cout<<fixed<<setprecision(2)<<PI*r*r*r*4/3<<endl;
    return 0;
}
