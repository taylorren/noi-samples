#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin>>n;

    float sum=0;
    short sign=1;
    
    for(int i=1;i<=n;i++)
    {
        float temp=1.0/i;
        sum+=sign*temp;
        sign=-sign;
    }
    cout<<fixed<<setprecision(4)<<sum<<endl;
    return 0;
}
