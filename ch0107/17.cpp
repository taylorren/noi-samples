#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string to_lower(string s)
{
    int len=s.length();
    string r;
    for(int i=0;i<len;i++)
    {
        char c=s[i];
        if(c>='A'&&c<='Z')
        {
            c=c-'A'+'a';
        }
        else if(c==' ')
        {
            continue;
        }
        
        r+=c;
    }

    return r;
}
int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    s1=to_lower(s1);
    s2=to_lower(s2);

    int r=s1.compare(s2);
    string res;
    if(r==0)
    {
        res="YES";
    }
    else
    {
        res="NO";
    }

    cout<<res<<endl;    

    return 0;
}
