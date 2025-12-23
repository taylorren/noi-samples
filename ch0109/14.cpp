#include <bits/stdc++.h>
using namespace std;

struct carpet
{
    int lower_left_x;
    int lower_left_y;
    int top_right_x;
    int top_right_y;
};

const int MAX = 10001;

bool is_in_carpet(carpet c, int x, int y)
{
    return (x >= c.lower_left_x && x <= c.top_right_x && y >= c.lower_left_y && y <= c.top_right_y);
}

int main()
{
    int n;
    cin >> n;

    carpet carpets[MAX];
    int a, b, g, k;

    // 创立一个虚拟的覆盖全部区域的地毯，且是第一个铺好的
    carpets[0].lower_left_x = 0;
    carpets[0].lower_left_y = 0;
    carpets[0].top_right_x = 100, 000;
    carpets[0].top_right_y = 100, 000;

    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> g >> k;
        carpets[i].lower_left_x = a;
        carpets[i].lower_left_y = b;
        carpets[i].top_right_x = a + g;
        carpets[i].top_right_y = b + k;
    }

    int x, y;
    cin >> x >> y;

    for (int i = n; i >= 0; i--)
    {
        if (is_in_carpet(carpets[i], x, y))
        {
            if (i == 0)
            {
                cout << -1 << endl;
                break;
            }
            else
            {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}