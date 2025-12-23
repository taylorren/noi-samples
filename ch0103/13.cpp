#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int g,s,b;
    g=n%10;
    s=(n-g)/10%10;
    b=(n-10*s-g)/100;
    
    cout<<g<<s<<b;


    return 0;
}
