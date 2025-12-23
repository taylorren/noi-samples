//这道题OJ的测试数据出错

#include <iostream>
#include <vector>
using namespace std;

using ull = unsigned long long;

int count_bits(ull x)
{
    int count = 0;
    while (x)
    {
        count += (x & 1);
        x >>= 1;
    }
    return count;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<ull> victims(N);
    vector<ull> families(M);

    for (int i = 0; i < N; ++i)
    {
        cin >> victims[i];
    }

    for (int i = 0; i < M; ++i)
    {
        cin >> families[i];
    }

    int count_relationships = 0;

    for (const auto &family : families)
    {
        for (const auto &victim : victims)
        {
            if (count_bits(family ^ victim) == 2)
            {
                ++count_relationships;
            }
        }
    }

    cout << count_relationships << endl;
    return 0;
}
