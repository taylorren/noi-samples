#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;
const int MAX_ID=101;

int main()
{
    int n;
    cin >> n;
    int people[MAX_ID]={};
    set<int> who_mentioned[MAX] ={};
    for(int i=1;i<=n;i++) // input every line that follows
    {
        int owner, mentions_count;
        cin>>owner>>mentions_count;

        for(int j=1;j<=mentions_count;j++)
        {
            int mentions_who;
            cin>>mentions_who;
            people[mentions_who]++;
            who_mentioned[mentions_who].insert(owner);
        }
    }

    //Output
    //Find the popular guy
    int count=0;
    int index;
    for(int i=1;i<=MAX_ID;i++)
    {
        if(people[i]>count)
        {
            index=i;
            count=people[i];
        }
    }

    cout<<index<<endl;
    for(int i:who_mentioned[index])
    {
        cout<<i<<" ";
    }
    return 0;
}
