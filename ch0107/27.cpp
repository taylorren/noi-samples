#include <bits/stdc++.h>

using namespace std;

string reverse_word(string word)
{
    string res="";
    int len=word.length();
    for(int i=len-1;i>=0;i--)
    {
        res+=word[i];
    }
    return res;
}

int main()
{
    string s;
    getline(cin, s);

    int len = s.length();
    string word = "";

    for (int i = 0; i < len; i++)
    {
        if (s[i] == ' ')
        {
            cout<<reverse_word(word);
            cout << " ";
            word="";
        }
        else
        {
            word += s[i];
        }
    }
    cout<<reverse_word(word)<<endl;

    return 0;
}
