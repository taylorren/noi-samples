#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 结构体用来存储每个植株的花生数量以及位置
struct Peanut
{
    int count;
    int row;
    int col;
};

// 按花生数量从大到小排序
bool compare(const Peanut &a, const Peanut &b)
{
    return a.count > b.count;
}

int max_peanuts(int M, int N, int K, vector<vector<int>> &field)
{
    vector<Peanut> peanuts;

    // 记录所有有花生的植株
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (field[i][j] > 0)
            {
                peanuts.push_back({field[i][j], i, j});
            }
        }
    }

    // 按花生数量排序
    sort(peanuts.begin(), peanuts.end(), compare);

    int current_time = 0;
    int total_peanuts = 0;
    int current_row = -1, current_col = -1;

    for (const auto &p : peanuts)
    {
        int number_of_peanuts = p.count;
        int row = p.row;
        int col = p.col;

        // 计算从路边或者当前位置跳到这棵植株的时间
        int time_to_start;
        if (current_row == -1)
        { // 从路边跳下来
            time_to_start = row + 1;
        }
        else
        { // 从当前植株跳到下一个
            time_to_start = abs(current_row - row) + abs(current_col - col);
        }

        // 计算返回路边的时间
        int time_to_return = row + 1;

        if (current_time + time_to_start + 1 + time_to_return <= K)
        {
            // 在这个植株摘花生
            current_time += time_to_start + 1;
            total_peanuts += number_of_peanuts;
            current_row = row;
            current_col = col;
        }
        else
        {
            // 如果再采摘无法按时返回，则停止
            break;
        }
    }

    return total_peanuts;
}

int main()
{
    int M, N, K;
    cin >> M >> N >> K;

    vector<vector<int>> field(M, vector<int>(N));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> field[i][j];
        }
    }

    int result = max_peanuts(M, N, K, field);
    cout << result << endl;

    return 0;
}
