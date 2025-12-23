#include <iostream>

using namespace std;

int main()
{
    int heights[11];
    heights[0]=0;
    for(int i=1;i<=10;i++)
    {
        cin>>heights[i];
    }
    int t;
    cin>>t;

    for(int i=1;i<=10;i++)
    {
        if(t+30>=heights[i])
        {
            heights[0]++;
        }
    }

    cout<<heights[0]<<endl;

    return 0;
}
