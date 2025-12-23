#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    long a,n;
    cin>>a>>n;
    double result=1.0;

    for(int i=1;i<=n;i++)
    {
        result*=(1+0.1/100);
    }
    cout<<fixed<<setprecision(4)<<a*result<<endl;
    
    return 0;
}
