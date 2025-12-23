#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    short slots[110]={0};
    list<int> result;

    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        if(slots[tmp]==1)
        {
            continue;
        }
        else
        {
            slots[tmp]=1;
            result.push_back(tmp);
        }
    }
    for(auto& r:result)
    {
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}