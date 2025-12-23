#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
    const int MAX=10001;
    int segments, length;
    cin>>length>>segments;
    bool trees[MAX];
    memset(trees, 1, sizeof(trees));

    for(int i=1;i<=segments;i++)
    {
        int s, e;
        cin>>s>>e;

        for(int j=s;j<=e;j++)
        {
            trees[j]=false;
        }
    }
    
    int count=0;
    for(int i=0;i<=length;i++)
    {
        if(trees[i])
        {
            count++;
        }
    }
    
    cout<<count<<endl;
    return 0;
}
