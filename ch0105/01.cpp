#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    float sum=0.0;
    int s;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>s;
        sum+=s;
    }

    float avg=1.0*sum/n;
    cout<<fixed<<setprecision(2)<<avg<<endl;
    return 0;
}
