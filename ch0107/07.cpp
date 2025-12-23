#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int len=s.length();
    string r;
    
    for(int i=0;i<len;i++)
    {
        char c=s[i];
        if(c=='A')
        {
            r.append("T");
        }
        else if(c=='T')
        {
            r.append("A");
        }
        else if (c=='G')
        {
            r.append("C");
        }
        else 
        {
            r.append("G");
        }
    }
    
    cout<<r<<endl;
    return 0;
}
