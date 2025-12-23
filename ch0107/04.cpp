#include <iostream>
#include <cstring>

using namespace std;

string check(string p1, string p2)
{
    string res;
    if (p1 == "Rock")
    {
        if (p2 == "Rock")
            res = "Tie";
        else if (p2 == "Scissors")
            res = "Player1";
        else // P2=Paper
            res = "Player2";
    }
    else if (p1 == "Scissors")
    {
        if (p2 == "Rock")
            res = "Player2";
        else if (p2 == "Scissors")
            res = "Tie";
        else // P2=Paper
            res = "Player1";
    }
    else // P1=Paper
    {
        if (p2 == "Rock")
            res = "Player1";
        else if (p2 == "Scissors")
            res = "Player2";
        else // P2=Paper
            res = "Tie";
    }

    return res;
}

int main()
{
    const int MAX = 101;

    int n;
    cin >> n;

    string p1[MAX], p2[MAX];
    string result[MAX];
    for (int i = 1; i <= n; i++)
    {
        cin >> p1[i] >> p2[i];
    }

    for (int i = 1; i <= n; i++)
    {
        result[i] = check(p1[i], p2[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        cout<<result[i]<<endl;
    }

    return 0;
}
