#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string upper_lower(string s)
{
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 'a' + 'A';
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}


int main()
{
    string s;
    getline(cin, s);

    s=upper_lower(s);
    cout << s << endl;
    return 0;
}
