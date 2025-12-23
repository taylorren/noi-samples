#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string upper_lower(string s)
{
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (isupper(s[i]))
        {
            s[i] = s[i] - 'A' + 'a';
        }
        else if (islower(s[i]))
        {
            s[i] = s[i] - 'a' + 'A';
        }
    }
    return s;
}

string reverse(string s)
{
    int len = s.length();
    string result;
    for (int i = 0; i < len; i++)
    {
        result += s[len - i - 1];
    }

    return result;
}

char shift(char c)
{
    if (islower(c))
    {
        c = (c - 'a' + 3) % 26 + 'a';
    }
    else if (isupper(c))
    {
        c = (c - 'A' + 3) % 26 + 'A';
    }
    return c;
}

int main()
{
    string s;
    cin >> s;

    s = upper_lower(s);
    s = reverse(s);

    string res;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        char c = shift(s[i]);
        res += c;
    }
    cout << res << endl;
    return 0;
}
