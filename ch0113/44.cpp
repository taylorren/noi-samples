#include <iostream>
#include <cstring>
using namespace std;
char c[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'S', 'Y', 'Z'};
int a[55], b[100000]; // a为原数，b为答案
int p, q;
char n[55]; // n为原数的字符串
int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        cin >> p;
        getchar();
        cin.getline(n, sizeof(n), ',');
        cin >> q; // 输入

        int len = strlen(n); // 转化为数字
        for (int i = 0; i < len; ++i)
        {
            a[i] = (n[i] >= 'A') ? (n[i] - 'A' + 10) : (n[i] - '0');
        }

        int k = 0, flag = 1; // k为答案的位数，flag用于标记结束情况
        while (1)
        {
            int ans = 0, temp = 0;
            for (int i = 0; i < len; ++i)
            { // 除k取余
                ans = (a[i] + temp * p) % q;
                a[i] = (a[i] + temp * p) / q;
                temp = ans;
            }
            b[k++] = ans;
            for (int i = 0; i < len; ++i)
            { // 遍历查看是否还有数字不为0的情况
                if (a[i] != 0)
                {
                    flag = 0;
                    break;
                }
                flag = 1;
            }
            if (flag)
                break;
        }
        for (int i = k - 1; i >= 0; i--)
        { // 输出
            cout << c[b[i]];
        }
        cout << endl;
    }
    return 0;
}
