#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    int size = 0, circle = 0;
    int i, j;
    cin >> N;
    int num[101][101];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {

            cin >> num[i][j];
        }
    }

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (num[i][j] <= 50)
            {
                size++;
                if (i == 0 || i == N - 1 || j == 0 || j == N - 1)
                {
                    circle++;
                }
                else if (num[i - 1][j] > 50 || num[i + 1][j] > 50 || num[i][j - 1] > 50 || num[i][j + 1] > 50)
                {
                    circle++;
                }
            }
    cout << size << " " << circle << endl;
    return 0;
}