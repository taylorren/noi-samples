#include <bits/stdc++.h>

using namespace std;

int main()
{
    string hay, needle1, needle2;

    string s;
    cin >> s;
    size_t pos1 = s.find(",");
    size_t pos2 = s.find(",", pos1 + 1);
    hay = s.substr(0, pos1);
    needle1 = s.substr(pos1 + 1, pos2 - pos1 - 1);
    needle2 = s.substr(pos2 + 1);

    // 在hay中找到needle2最后一次出现的位置
    size_t pos3 = hay.rfind(needle2);
    if (pos3 != string::npos)
    {
        // 在hay中找到needle1第一次出现的位置
        size_t pos1 = hay.find(needle1);
        if (pos1 != string::npos)
        {
            // 计算两根针之间的距离
            int distance = pos3 - pos1 - needle1.length();
            if (distance >= 0)
            {
                cout << distance << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}