#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float price[11]={0, 28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};
    int qty;
    for(int i=1;i<=10;i++)
    {
        cin>>qty;
        price[0]+=qty*price[i];
    }

    cout<<fixed<<setprecision(1)<<price[0]<<endl;

    return 0;
}
