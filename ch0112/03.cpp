#include <bits/stdc++.h>
using namespace std;

bool risk(float temp, int cough)
{
    return (temp >= 37.5 && cough == 1);
}

int main()
{
    int n;
    cin >> n;
    int count = 0;
    string result = "";

    for (int i = 1; i <= n; i++)
    {
        string name;
        float temp;
        int cough;

        cin >> name >> temp >> cough;

        if (risk(temp, cough))
        {
            result += name + "\n";
            count++;
        }
    }

    cout << result << count << endl;

    return 0;
}