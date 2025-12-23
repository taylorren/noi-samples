#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float sum=0.0;
    float s;

    for(int i=1;i<=12;i++)
    {
        cin>>s;
        sum+=s;
    }

    float avg=sum/12;
    cout<<"$"<<fixed<<setprecision(2)<<avg<<endl;
    return 0;
}
