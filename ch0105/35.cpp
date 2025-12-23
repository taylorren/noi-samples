#include <iostream>
#include <iomanip>
using namespace std;

long fact(int n)
{
    long prod=1;
    for(int i=2;i<=n;i++)
    {
        prod*=i;
    }

    return prod;
}

int main()
{
    int n;
    cin>>n;
    double sum=1.0;
    for(int i=1;i<=n;i++)
    {
        sum+=1.0/(double)fact(i);
    }
    cout<<fixed<<setprecision(10)<<sum<<endl;
    return 0;
}
