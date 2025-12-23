#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int MAX = 101;
    int m[MAX][MAX];
    int rows, cols;
    int sum = 0;

    cin >> rows >> cols;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            int tmp;

            cin >> tmp;
            m[i][j] = tmp;
        }
    }
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {

            if (i == 1 || j == 1 || i == rows || j == cols)
            {
                sum += m[i][j];
            }
        }
    }
    cout << sum << endl;

    return 0;
}
