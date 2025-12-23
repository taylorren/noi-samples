#include <iostream>
#include <cstring>
using namespace std; // n代表整数部分，m代表小数部分
int a_n[101], b_n[101], a_m[101], b_m[101], n[101], m[101];
char a[101], b[101]; // ab分别代表不同的两数
int main()
{
    cin >> a >> b;
    int a_len = strlen(a);
    int b_len = strlen(b);
    int a_n_len = 0, b_n_len = 0, a_m_len = 0, b_m_len = 0;
    bool flag = true;
    for (int i = 0; i < a_len; ++i)
    { // 分解
        if (a[i] == '.')
        {
            flag = false;
            continue;
        }
        flag ? a_n[a_n_len++] = a[i] - '0' : a_m[a_m_len++] = a[i] - '0';
    }
    int a_nn[101]; // 整数倒序，便于计算
    memset(a_nn, 0, sizeof(a_nn));
    for (int i = 0; i < a_n_len; ++i)
    {
        a_nn[i] = a_n[a_n_len - 1 - i];
    }
    flag = true; // b
    for (int i = 0; i < b_len; ++i)
    {
        if (b[i] == '.')
        {
            flag = false;
            continue;
        }
        flag ? b_n[b_n_len++] = b[i] - '0' : b_m[b_m_len++] = b[i] - '0';
    }
    int b_nn[101];
    memset(b_nn, 0, sizeof(b_nn));
    for (int i = 0; i < b_n_len; ++i)
    {
        b_nn[i] = b_n[b_n_len - 1 - i];
    }

    int jw = 0;                                          // 进位
    int max_m = (a_m_len > b_m_len ? a_m_len : b_m_len); // 先开始小数
    for (int i = max_m; i >= 0; --i)
    {
        m[i] = a_m[i] + b_m[i] + jw;
        jw = m[i] / 10;
        m[i] %= 10;
    }
    int max_n = a_n_len > b_n_len ? a_n_len : b_n_len; // 整数
    for (int i = 0; i < max_n; ++i)
    {
        n[i] = a_nn[i] + b_nn[i] + jw;
        jw = n[i] / 10;
        n[i] %= 10;
    }
    if (jw > 0)
    { // 进位
        max_n += 1;
        n[max_n - 1] = jw;
    }
    for (int i = max_n - 1; i >= 0; --i)
    { // 输出
        cout << n[i];
    }
    cout << ".";
    while (m[max_m - 1] == 0)
    { // 去0
        max_m--;
    }
    for (int i = 0; i < max_m; ++i)
    {
        cout << m[i];
    }
}
