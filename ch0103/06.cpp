#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b;
    cin>>a>>b;
    float p=1.0*b/a*100;
    cout<<fixed<<setprecision(3)<<p<<"%"<<endl;

    return 0;
}
