#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int number;
    int q,b,s,g;
    int count=0;

    for(int i=1;i<=n;i++)
    {
        cin>>number;
        g=number%10;
        s=number%100/10;
        b=number%1000/100;
        q=number/1000;
        
        if(g-q-b-s>0)
        {
            count++;
        }
    }

    cout<<count<<endl;

    return 0;
}
