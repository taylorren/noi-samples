#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int MAX = 105;
    int n;
    cin >> n;

    int max = -100;
    string highest = "";

    for (int i = 1; i <= n; i++)
    {
        int score;
        string name;
        cin >> score >> name;
        if (score > max)
        {
            max=score;
            highest = name;
        }
    }

    cout << highest << endl;

    return 0;
}
