#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 体重分别为zhao, qian, sun, li
    for(int zhao = 10; zhao <= 50; zhao += 10)
    {
        for(int qian = 10; qian <= 50; qian += 10)
        {
            for(int sun = 10; sun <= 50; sun += 10)
            {
                for(int li = 10; li <= 50; li += 10)
                {
                    // 所有体重都不相同
                    if(zhao == qian || zhao == sun || zhao == li ||
                       qian == sun || qian == li || sun == li)
                    {
                        continue;
                    }

                    // 赵钱之和等于孙李之和
                    if(zhao + qian != sun + li)
                    {
                        continue;
                    }

                    // 赵李之和大于孙钱之和
                    if(zhao + li <= sun + qian)
                    {
                        continue;
                    }

                    // 赵孙之和小于钱的体重
                    if(zhao + sun >= qian)
                    {
                        continue;
                    }

                    // 找到答案，按体重从小到大排序输出
                    vector<pair<char, int>> people = {
                        {'z', zhao}, {'q', qian}, {'s', sun}, {'l', li}};

                    // 冒泡排序
                    for(int i = 0; i < 3; i++)
                    {
                        for(int j = 0; j < 3 - i; j++)
                        {
                            if(people[j].second > people[j + 1].second)
                            {
                                swap(people[j], people[j + 1]);
                            }
                        }
                    }

                    // 输出结果
                    for(const auto& p : people)
                    {
                        cout << p.first << " " << p.second << endl;
                    }

                    return 0;
                }
            }
        }
    }

    return 0;
}