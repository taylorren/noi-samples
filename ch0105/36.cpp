#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float x;
    int n;
    cin>>x>>n;

    float result=1;
    float p=x;
    for(int i=1;i<=n;i++)
    {
        result+=x;
        x=x*p;
    }
    cout<<fixed<<setprecision(2)<<result<<endl;

    return 0;
}
