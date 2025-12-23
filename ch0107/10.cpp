#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        char c = s[i];
        if(c>='A'&&c<='Z')
        {
            c=(c-'A'+21)%26+'A';
        }
        s[i]=c;

    }

    cout << s<<endl;
    return 0;
}
