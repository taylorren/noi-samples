#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double a, b, c, d, x;
    cin>>x>>a>>b>>c>>d;
    double p=a*x*x*x+b*x*x+c*x+d;
    cout<<fixed<<setprecision(7)<<p<<endl;

    return 0;
}
