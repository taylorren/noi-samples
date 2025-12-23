#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string s;
    cin>>s;

    char needle, rep;
    cin>>needle>>rep;

    int len=s.length();
    for(int i=0;i<len;i++)
    {
        if(s[i]==needle)
        {
            s[i]=rep;
        }
    }

    cout<<s<<endl;

    return 0;
}
