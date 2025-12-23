#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int total=0;
    int streak=1;

    for(int i=1;i<=n;)
    {
        for(int j=1;j<=streak;j++)
        {
            total+=streak;
            i++;
            if(i>n)
            {
                break;
            }
        }
        streak++;

    }
        
    cout<<total<<endl;
    return 0;
}
