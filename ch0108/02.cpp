#include <bits/stdc++.h>

using namespace std;

string output_same_row(int row, int N)
{
    ostringstream buffer;
    for (int col = 1; col <= N; col++)
    {
        buffer << "(" << row << "," << col << ") ";
    }

    return buffer.str();
}

string output_same_col(int col, int N)
{
    ostringstream buffer;
    for (int row = 1; row <= N; row++)
    {
        buffer << "(" << row << "," << col << ") ";
    }

    return buffer.str();
}

string output_main_diag(int row, int col, int N)
{
    int diff = row - col; // 主对角线性质：（行数-列数）是恒定的

    ostringstream buffer;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i - j == diff)
            {
                buffer << "(" << i << "," << j << ") ";
            }
        }
    }
    return buffer.str();
}

string output_reve_diag(int row, int col, int N)
{
    int diff = row + col; // 次对角线性质：（行数+列数）是恒定的
    ostringstream buffer;
    for (int i = N; i >= 1; i--)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i + j == diff)
            {
                buffer << "(" << i << "," << j << ") ";
            }
        }
    }
    return buffer.str();
}

int main()
{
    int N, row, col;
    cin >> N >> row >> col;

    cout << output_same_row(row, N) << endl;
    cout << output_same_col(col, N) << endl;
    cout << output_main_diag(row, col, N) << endl;
    cout << output_reve_diag(row, col, N) << endl;

    return 0;
}
