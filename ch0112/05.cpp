#include <bits/stdc++.h>
using namespace std;

 void str_to_lower(string &str)
{
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        str[i]=tolower(str[i]);
    }
}

int main()
{
    string needle, sentence;

    getline(cin, needle);
    getline(cin, sentence);
    
    str_to_lower(needle);
    str_to_lower(sentence);

    needle=" "+needle+" ";
    sentence=" "+sentence+" ";

    if(sentence.find(needle)==string::npos)
    {
        cout<<-1<<endl;
    }
    else 
    {
        int pos=sentence.find(needle);
        int t=pos;
        int count=0;

        while(t!=string::npos)
        {
            count++;
            t=sentence.find(needle, t+1);
        }

        cout<<count<<" "<<pos<<endl;
    }


    return 0;
}