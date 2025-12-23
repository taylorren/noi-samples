#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int count = 0;
    if (isdigit(s[0]))
    {
        cout << "no" << endl;
        return 0;
    }

    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        char c = s[i];
        bool is_digit = isdigit(c);
        bool is_letter = islower(c) || isupper(c);
        bool is_underscore = (c == '_');
        if (!is_digit && !is_letter && !is_underscore)
        {
            cout << "no" << endl;
            return 0;
        }
        else
        {
            count++;
        }
    }
    if (count == len)
        cout << "yes" << endl;

    return 0;
}
