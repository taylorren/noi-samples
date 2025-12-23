#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    char c;
    int i;
    float f;
    double d;
    cin>>c>>i>>f>>d;

    cout<<c<<" ";
    cout<<i<<" ";
    cout<<fixed<<setprecision(6)<<f<<" ";
    cout<<fixed<<setprecision(6)<<d<<endl;

    return 0;
}
