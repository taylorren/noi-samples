#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int MAX=101;
    int n, a[MAX][MAX] = {0};
    int i, j, r, c, rows = 0, columns = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            a[0][j] = (a[0][j] + a[i][j]) % 2; // 判断此数组是否是偶数
            a[i][0] = (a[i][0] + a[i][j]) % 2;
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (a[i][0] > 0)
        { // 判断i行第0个数字是否大于0
            r = i;
            rows++; // 计算出有多少数字大于0
        }
    }
    for (j = 1; j <= n; j++)
    {
        if (a[0][j] > 0)
        { // 判断j列第0个数字是否大于0
            c = j;
            columns++;
        }
    }
    if (rows == 0 && columns == 0)
    { // rows和columns都是0，矩阵符合条件，OK
        cout << "OK" << endl;
    }
    else if (rows == 1 && columns == 1)
    { // rows和columns都是1,行列各有一奇数，就输出奇数行和奇数列交叉的位置
        cout << r << " " << c << endl;
    }
    else
    { // 当行和列都有不止一个奇数，不行
        cout << "Corrupt" << endl;
    }
    return 0;
}
