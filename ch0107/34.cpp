#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string s)
{
    string s1=s;
    reverse(s1.begin(), s1.end());
    return s == s1;
}

int main()
{
    string s;
    cin>>s;

    int len =s.length();
    for(int l=2;l<=len;l++)
    {
        for(int i=0;i<=len-l;i++)
        {
            string sub=s.substr(i,l);
            if(is_palindrome(sub))
            {
                cout<<sub<<endl;
            }
        }

    }
    return 0;
}
