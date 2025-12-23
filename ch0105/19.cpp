#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int roofs;
    cin>>roofs;

    float minutes=0.0;
    double x, y;
    int number;
    for(int i=1;i<=roofs;i++)
    {
        cin>>x>>y>>number;
        float travel=sqrt(x*x+y*y)/50*2.0;
        float load_unload=number*1.5;
        minutes=minutes+travel+load_unload;
    }

    cout<<ceil(minutes)<<endl;
}
