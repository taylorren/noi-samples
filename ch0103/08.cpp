#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double f;
    cin>>f;
    double c=(f-32)*5.0/9;
    cout<<fixed<<setprecision(5)<<c<<endl;

    return 0;
}
