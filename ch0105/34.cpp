#include <iostream>
#include <iomanip>
using namespace std;

int fact(int n)
{
    int prod=1;
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
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=fact(i);
    }
    cout<<sum<<endl;
    return 0;
}
