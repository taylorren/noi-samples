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
    char res;
    if(r==0)
    {
        res='=';
    }
    else if(r<0)
    {
        res='<';
    }
    else 
    {
        res='>';
    }

    cout<<res<<endl;    

    return 0;
}
