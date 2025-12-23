#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int max=-1;
    int min=10000;
    int s;

    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(s>max)
        {
            max=s;
        }
        if(s<min)
        {
            min=s;
        }
    }

    cout<<max-min<<endl;
    return 0;
}
