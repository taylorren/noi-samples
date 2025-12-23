#include <iostream>

using namespace std;

int main()
{
    int N, m;
    cin>>N>>m;

    int count=0;
    int v;
    for(int i=1;i<=N;i++)
    {
        cin>>v;
        if(v==m)
        {
            count++;
        }
    }
    cout<<count<<endl;
    
    return 0;
}
