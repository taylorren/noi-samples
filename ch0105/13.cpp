#include <iostream>

using namespace std;

int main()
{
    long a, n;
    cin>>a>>n;
    long long result=1;

    for(int i=1;i<=n;i++)
    {
        result*=a;
    }
    cout<<result<<endl;
    
    return 0;
}
