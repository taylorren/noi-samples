#include <bits/stdc++.h>
using namespace std;

int main()
{
    string hay, needle;
    cin>>hay>>needle;
    
    if(hay.size()<needle.size())
    {
        swap(hay, needle);
    }

    int rotation, len=hay.length();
    bool res=false;
    for(rotation=1;rotation<=len;rotation++)
    {
        if(hay.find(needle)!=string::npos) // Got it!
        {
            res=true;
            break;
        }
        char start=hay[0];
        hay=hay.erase(0,1)+start; //拼接一次
    }

    if(res)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }

    return 0;
}
