#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;

    string r="";
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        r+=s[len-i-1];
    }

    if(s==r)
    {
        cout<<"yes";
    }
    else 
    {
        cout<<"no";
    }

    cout<<endl;

    
    return 0;
}
