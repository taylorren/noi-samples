#include <iostream>
#include <cstring>
#include <string>

using namespace std;

bool do_mapping(string encrypted, string original, char *mapping)
{
    int len = encrypted.length();
    bool success = true;
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        char e = encrypted[i];
        char o = original[i];

        if (mapping[o - 'A'] == '-') // 新的字母
        {
            mapping[o - 'A'] = e;
            count++;
        }
        else
        {
            if (mapping[o - 'A'] == e) // 重复出现，且相同
            {
                continue;
            }
            else // 重复出现，且不同的e对应了同一个o
            {
                success = false;
                break; // 不用循环了，肯定出错了
            }
        }
    }
    if (count != 26) // 26个字母没有全部出现
    {
        success = false;
    }
    return success;
}

string decode(string s, char mapping[26])
{
    int len = s.length();
    string res = "";

    for (int i = 0; i < len; i++)
    {
        for(int j=0;j<26;j++)
        {
            if(mapping[j]==s[i])
            {
                res+=(j+'A');
            }
        }
    }
    return res;
}

int main()
{
    string encrypted, original, s;
    cin >> encrypted >> original >> s;
    char mapping[26];
    fill(mapping, mapping+26, '-');

    int len = encrypted.length();

    bool success = do_mapping(encrypted, original, mapping);
    if (!success)
    {
        cout << "Failed" << endl;
    }
    else
    {
        s = decode(s, mapping);
        cout<<s<<endl;
    }
    return 0;
}
