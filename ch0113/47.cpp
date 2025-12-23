#include <iostream>
#include <cstring>
using namespace std;
int factora[105] = {};
int factorb[105] = {};
int dif[205] = {};
int cnt1, cnt2;
int *sub(int *a, int *b)
{
    for (int i = 0; i < cnt1; i++)
    {
        if (a[i] < b[i])
        {
            a[i + 1]--;
            a[i] = a[i] + 10;
        }
        dif[i] = a[i] - b[i];
    }
    return dif;
}
bool test(int *a, int *b)
{
    for (int j = cnt1 - 1; j >= 0; j--)
    {
        if (a[j] > b[j])
            return true;
        if (a[j] < b[j])
            return false;
    }
    return true;
}
int main()
{
    int result[105] = {};
    memset(dif, 0, sizeof(dif));
    cnt1 = 0;
    cnt2 = 0;
    char inputa[200];
    char inputb[200];
    cin >> inputa;
    cin >> inputb;
    cnt1 = strlen(inputa);
    cnt2 = strlen(inputb);
    // 去除前导0
    int nozero1, nozero2;
    for (int i = 0; i < cnt1; i++)
        if (inputa[i] != '0')
        {
            nozero1 = i;
            break;
        }
    for (int i = 0; i < cnt2; i++)
        if (inputb[i] != '0')
        {
            nozero2 = i;
            break;
        }
    cnt1 -= nozero1;
    for (int i = 0; i < cnt1; i++)
    {
        inputa[i] = inputa[i + nozero1];
    }
    cnt2 -= nozero2;
    for (int i = 0; i < cnt2; i++)
        inputb[i] = inputb[i + nozero2];
    // 准备移位相减，temp是每次减后的结果
    for (int i = 0; i < cnt1; i++)
        factora[cnt1 - 1 - i] = inputa[i] - '0';
    int *temp = factora;
    for (int j = 0; j <= cnt1 - cnt2; j++)
    {
        memset(factorb, 0, sizeof(factorb));
        for (int i = 0; i < cnt2; i++)
            factorb[cnt1 - 1 - j - i] = inputb[i] - '0';
        while (test(temp, factorb))
        {
            result[cnt1 - cnt2 - j]++;
            temp = sub(temp, factorb);
        }
    }
    int j;
    for (j = cnt1 - 1; j >= 0; j--)
    {
        if (result[j] > 0)
            break;
    }
    if (j == -1)
        j = 0;
    for (int i = j; i >= 0; i--)
        cout << result[i];
    return 0;
}
