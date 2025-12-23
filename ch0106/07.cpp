#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
    const int MAX=3000;
    int count, start, end;
    int array[MAX]={0};

    cin>>count;
    cin>>start;

    if(count==1)
    {
        cout<<"Jolly"<<endl;
        return 0;
    }

    for(int i=1;i<count;i++)
    {
        cin>>end;
        int pos=abs(start-end);
        array[pos]++;
        start=end;
    }

    for(int i=1;i<count;i++)
    {
        if(array[i]!=1)
        {
            cout<<"Not jolly"<<endl;
            return 0;
        }
    }

    cout<<"Jolly"<<endl;

    return 0;
}
