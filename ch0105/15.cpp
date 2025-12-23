#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int r, m, y;
    cin>>r>>m>>y;
    double compound=1.0;

    for(int i=1;i<=y;i++)
    {
        compound*=(1+r/100.0);
    }
    int income=m*compound;

    cout<<income<<endl;
    
    return 0;
}
