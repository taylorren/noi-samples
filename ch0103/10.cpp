#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float r1, r2;
    cin>>r1>>r2;

    cout<<fixed<<setprecision(2)<<1/(1/r1+1/r2)<<endl;
    return 0;
}
