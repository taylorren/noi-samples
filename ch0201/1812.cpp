#include <bits/stdc++.h>
using namespace std;

/*
枚举
 */
// 存储一组解
struct Solution
{
    int a, b, c, d;
    Solution(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
};

// 比较函数，用于排序
bool compare(const Solution &s1, const Solution &s2)
{
    if (s1.a != s2.a)
        return s1.a < s2.a;
    if (s1.b != s2.b)
        return s1.b < s2.b;
    if (s1.c != s2.c)
        return s1.c < s2.c;
    return s1.d < s2.d;
}

int main()
{
    int N;
    cin >> N;

    vector<Solution> solutions;

    // 预先计算立方值，避免重复计算
    vector<long long> cubes(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cubes[i] = (long long)i * i * i;
    }

    // 枚举 b, c, d
    for (int b = 2; b <= N; b++)
    {
        for (int c = b; c <= N; c++)
        {
            for (int d = c; d <= N; d++)
            {
                // 计算立方和
                long long sum = cubes[b] + cubes[c] + cubes[d];

                // 二分查找是否存在对应的 a
                int left = d, right = N;
                while (left <= right)
                {
                    int mid = (left + right) / 2;
                    if (cubes[mid] == sum)
                    {
                        solutions.push_back(Solution(mid, b, c, d));
                        break;
                    }
                    else if (cubes[mid] < sum)
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
            }
        }
    }

    // 按要求排序
    sort(solutions.begin(), solutions.end(), compare);

    // 输出结果
    for (const auto &sol : solutions)
    {
        cout << "Cube = " << sol.a << ", Triple = ("
             << sol.b << "," << sol.c << "," << sol.d << ")" << endl;
    }

    return 0;
}
