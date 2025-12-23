#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const int months=12;
    const int income=300;
    int deposit=0;
    int budget;
    int balance=0;

    for(int i=1;i<=months;i++)
    {
        cin>>budget;
        balance=balance+income-budget;
        if(balance<0)
        {
            cout<<-i<<endl;
            return 0;
        }

        if(balance>=100)
        {
            deposit+=balance/100;
            balance%=100;
        }
    }
    cout<<deposit*120+balance<<endl;
    return 0;
}
