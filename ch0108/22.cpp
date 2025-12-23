#include <iostream>
using namespace std;

int a[1001][1001];
int now = 1;
int tot = 0;
int row, col;

int main()
{
    int n;
    cin >> n;
    int c = 2 * n - 1;

    while (tot != (c * c))
    {
        if (tot == 0) //第一个：按照规则1放置：第一行中间
        {
            a[1][c / 2 + 1] = now;
            now++;
            row = 1;
            col = c / 2 + 1;
            tot++;
        }
        else if (row == 1 && col != c)  //规则2.a：如果该数字在第一行，则下一个数字写在最后一行，列数为该数字的右一列
        {
            a[c][col + 1] = now;
            now++;
            tot++;
            row = c;
            col = col + 1;
        }
        else if (col == c && row != 1) //规则2.b：如果该数字在最后一列，则下一个数字写在第一列，行数为该数字的上一行
        {
            a[row - 1][1] = now;
            now++;
            tot++;
            row = row - 1;
            col = 1;
        }
        else if ((row == 1 && col == c) || (a[row - 1][col + 1] != 0)) //在右上角或者右上角不空
        {
            a[row + 1][col] = now;
            now++;
            tot++;
            row = row + 1;
        }
        else //右上角
        {
            a[row - 1][col + 1] = now;
            now++;
            tot++;
            row = row - 1;
            col = col + 1;
        }
    }
    for (int i = 1; i <= c; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}