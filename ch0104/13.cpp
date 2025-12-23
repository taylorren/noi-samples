#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float x;
    cin>>x;

    float y;
    if(0<=x&&x<5)
    {
        y=-x+2.5;
    }
    else if(5<=x&&x<10) 
    {
        y=2-1.5*(x-3)*(x-3);
    }
    else 
    {
        y=x/2.0-1.5;
    }

    cout<<fixed<<setprecision(3)<<y<<endl;

    return 0;
}
