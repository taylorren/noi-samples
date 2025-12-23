#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int len=s.length();

    for(int i=0;i<len;i++)
    {
        char c1, c2;
        c1=s[i];
        c2=s[(i+1)%len];

        char r=char(c1+c2);
        cout<<r;
    }
    cout<<endl;
    
    return 0;
}
