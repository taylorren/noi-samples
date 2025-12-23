#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    const double PI=3.14159;
    int h, r;
    cin>>h>>r;
    double v=PI*r*r*h;
    double n=20.0*1000/v;
    cout<<ceil(n)<<endl;
    return 0;
}
