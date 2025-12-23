#include <bits/stdc++.h>
using namespace std;


int main()
{
    string s;
    getline(cin, s);

    istringstream iss(s);

    set<string> words;
    string word;
    while(iss>>word)
    {
        words.insert(word);
    }

    
    
    for(auto& e:words)
    {
        cout<<e<<endl;
    }
    return 0;
}
