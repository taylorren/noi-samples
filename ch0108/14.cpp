#include <bits/stdc++.h>
using namespace std;

int main()
{
    char mines[200][200];
    int n, m, count;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        string tmp;
        cin >> tmp;

        for (int j = 1; j <= m; j++)
        {
            mines[i][j] = tmp[j - 1];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mines[i][j] == '*')
            {
                cout << "*";
            }
            else
            {
                count = 0;
                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        if (x >= 1 && x <= n && y >= 1 && y <= m && mines[x][y] == '*')
                        {
                            count++;
                        }
                    }
                }
                cout << count;
            }
        }
        cout << endl;
    }

    return 0;
}
