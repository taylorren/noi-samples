#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const int MAX=1001;
    int n;
    cin>>n;

    int a[MAX]={0}, b[MAX]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }

    int dot_product=0;
    for(int i=1;i<=n;i++)
    {
        dot_product+=a[i]*b[i];
    }

    cout<<dot_product<<endl;
    
    return 0;
}
