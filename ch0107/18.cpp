#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    cin>>s1;
    cin>>s2;
    
    if(s1.length()>s2.length())
    {
        swap(s1,s2);
    }

    if(s2.find(s1)!=string::npos)
    {
        cout<<s1<<" is substring of "<<s2;
    }
    else
    {
        cout<<"No substring";
    }

    cout<<endl;    

    return 0;
}
