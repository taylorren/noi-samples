#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// 检查某人说的话的正确性，返回正确的句子数
int checkStatements(char person, int a, int b, int c)
{
    int correct = 0;
    if(person == 'A')
    {
        if(b > a) correct++;  // B比我吃的多
        if(c == a) correct++; // C和我吃的一样多
    }
    else if(person == 'B')
    {
        if(a > b) correct++;  // A比我吃的多
        if(a > c) correct++;  // A也比C吃的多
    }
    else // C
    {
        if(c > b) correct++;  // 我比B吃得多
        if(b > a) correct++;  // B比A吃的多
    }
    return correct;
}

int main()
{
    string order = "ABC";
    // 遍历所有可能的排序
    do
    {
        // 根据位置分配饭量（位置越靠后，饭量越大）
        int food[3] = {1, 2, 3};
        int a = food[order.find('A')];
        int b = food[order.find('B')];
        int c = food[order.find('C')];

        // 计算每个人说对的句子数
        vector<pair<int, int>> results;  // pair<饭量, 正确数>
        results.push_back({a, checkStatements('A', a, b, c)});
        results.push_back({b, checkStatements('B', a, b, c)});
        results.push_back({c, checkStatements('C', a, b, c)});

        // 检查是否满足反序关系
        bool valid = true;
        for(int i = 0; i < 3; i++)
        {
            for(int j = i + 1; j < 3; j++)
            {
                if((results[i].first < results[j].first) != 
                   (results[i].second > results[j].second))
                {
                    valid = false;
                    break;
                }
            }
            if(!valid) break;
        }

        if(valid)
        {
            cout << order << endl;
            break;
        }
    } while(next_permutation(order.begin(), order.end()));

    return 0;
}