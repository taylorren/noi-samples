#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int h;
    cin >> h;
    vector<vector<int>> triangle(h);

    // 输入三角形数据
    for(int i = 0; i < h; ++i)
    {
        triangle[i].resize(i + 1);
        for(int j = 0; j <= i; ++j)
        {
            cin >> triangle[i][j];
        }
    }

    // 从倒数第二行开始更新
    for(int i = h - 2; i >= 0; --i)
    {
        for(int j = 0; j <= i; ++j)
        {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    // 输出结果
    cout << triangle[0][0] << endl;
    return 0;
}