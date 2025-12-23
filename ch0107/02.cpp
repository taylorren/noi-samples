#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    string s;
    cin>>s;

    int count[26]={0};
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        count[s[i]-'a']++;
    }

    for(int i=0;i<len;i++)
    {
        if(count[s[i]-'a']==1)
        {
            cout<<s[i]<<endl;
            return 0;
        }
    }

    cout<<"no"<<endl;
    
    return 0;
}
