#include <iostream>

using namespace std;

int main()
{
    int n, i=2;
    cin>>n;

    while(i)
    {
        bool prime=true;
        for(int j =2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                prime=false;
                break;
            }
        }
        if(prime)
        {
            n--;
            if(n==0)
            {
                break;
            }

        }
        i++;
    }
    cout<<i<<endl;
    return 0;
}
