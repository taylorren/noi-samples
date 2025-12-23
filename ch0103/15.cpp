#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n, x, y;
    cin>>n>>x>>y;

    float r=n-ceil(1.0*y/x);
    cout<<r<<endl;
    
    return 0;
}
