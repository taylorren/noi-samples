#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int sum=0;
    int s;

    for(int i=1;i<=n;i++)
    {
        cin>>s;
        sum+=s;
    }

    double avg=1.0*sum/n;
    cout<<sum<<" "<<fixed<<setprecision(5)<<avg<<endl;
    return 0;
}
