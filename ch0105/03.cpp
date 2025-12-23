#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin>>n;

    float sum=0.0;
    float s;

    for(int i=1;i<=n;i++)
    {
        cin>>s;
        sum+=s;
    }

    float avg=sum/n;
    cout<<fixed<<setprecision(4)<<avg<<endl;
    return 0;
}
