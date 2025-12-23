#include <bits/stdc++.h>
using namespace std;

int counts[26]={0}; //各个字母的出现次数
int most=0;

void process(string s)
{
    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        if(c>='A'&&c<='Z')
        {
            counts[c-'A']++;
        }
    }
}

void display(int most)
{
    string s="  ";
    for(int i=most;i>=1;i--)
    {
        for(int j=0;j<26;j++)
        {
            if(counts[j]>=i)
            {
                s="* ";
            }
            else 
            {
                s="  ";
            }

            cout<<s;
        }
        cout<<endl;
    }
    for(int i=0;i<26;i++)
    {
        cout<<char(i+'A')<<" ";
    }
}

int main()
{
    

    string s;
    for(int i=1;i<=4;i++)
    {
        getline(cin, s);
        process(s);
    }
    
    for(int i=0;i<26;i++)
    {
        if(counts[i]>most)
        {
            most=counts[i];
        }
    }

    display(most);

    return 0;
}
