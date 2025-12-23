#include <iostream>
#include <vector>

using namespace std;

const int MOD = 32767;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 预处理Pell数列
    vector<int> pell(3000);
    pell[1] = 1;
    pell[2] = 2;
    int period = 0;
    
    // 寻找周期
    for(int i = 3; i <= 2500; i++)
    {
        pell[i] = (2 * pell[i - 1] + pell[i - 2]) % MOD;
        // 由于初始值是1,2，我们寻找这个模式重复的地方
        if(pell[i] == 2 && pell[i - 1] == 1)
        {
            period = i - 2;
            break;
        }
    }
    
    int n;
    cin >> n;
    
    while(n--)
    {
        int k;
        cin >> k;
        if(period)
        {
            k = k % period;
            if(k == 0) k = period;
        }
        cout << pell[k] << '\n';
    }
    
    return 0;
}