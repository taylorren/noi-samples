#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    
    int len=s.length();
    if(s.find("er", len-2)!=-1)
    {
        s=s.substr(0, len-2);
        
    } else if(s.find("ly", len-2)!=-1){
        s=s.substr(0, len-2);
    }
    else if(s.find("ing", len-3)!=-1)
    {
        s=s.substr(0, len-3);
    }
    cout<<s<<endl;
    return 0;
}
