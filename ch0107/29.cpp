#include <bits/stdc++.h>

using namespace std;

int main()
{
    string isbn;
    cin >> isbn;

    int len = isbn.length();
    int multiply = 1;
    int sum = 0;

    for (int i = 0; i < len - 1; i++)
    {
        char c = isbn[i];
        if (c == '-')
        {
            continue;
        }
        sum += multiply * (c - '0');
        multiply++;
    }
    int checksum = sum % 11;
    char check;
    if (checksum == 10)
    {
        check = 'X';
    }
    else
    {
        check = checksum + '0';
    }

    if (check == isbn[len - 1])
    {
        cout << "Right" << endl;
        return 0;
    }
    else
    {
        isbn[len - 1] = check;
        cout << isbn << endl;
        return 0;
    }

    return 0;
}
