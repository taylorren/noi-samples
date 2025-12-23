#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int max=-1;
    int s;

    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(s>max)
        {
            max=s;
        }
    }

    cout<<max<<endl;
    return 0;
}
