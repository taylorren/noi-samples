#include <iostream>
using namespace std;

bool isValid(long long peaches, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(peaches <= n || peaches % n != 1)
            return false;
        peaches = peaches - 1 - (peaches - 1) / n;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    // 从最小可能的数开始，每次增加n
    // 因为x-1必须是n的倍数，所以x%n必须为1
    long long peaches = 1;
    while(true)
    {
        peaches = peaches + n; // 下一个可能的数
        if(isValid(peaches, n))
        {
            cout << peaches << endl;
            break;
        }
    }
    return 0;
}