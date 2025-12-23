#include <iostream>

using namespace std;

int main()
{
    const int MAX = 101;
    int n[MAX];
    int count, needle;
    cin >> count;
    n[0] = 0;

    for(int i = 1; i <= count; i++)
    {
        cin >> n[i];
    }

    cin >> needle;
    for(int i = 1; i <= count; i++)
    {
        if(n[i] == needle)
        {
            n[0]++;
        }
    }

    cout << n[0] << endl;
    return 0;
}
