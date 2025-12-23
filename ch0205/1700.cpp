#include <iostream>
#include <vector>
using namespace std;

class EightQueens
{
private:
    static const int N = 8;
    vector<vector<int>> solutions;
    vector<int> current;
    int solutionCount = 0;

    bool isValid(int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            if (current[i] == col ||
                abs(current[i] - col) == abs(i - row))
            {
                return false;
            }
        }
        return true;
    }

    void solve(int row)
    {
        if (row == N)
        {
            solutions.push_back(current);
            solutionCount++;
            return;
        }

        for (int col = 0; col < N; col++)
        {
            if (isValid(row, col))
            {
                current[row] = col;
                solve(row + 1);
            }
        }
    }

public:
    EightQueens() : current(N) {}

    void findAllSolutions()
    {
        solve(0);
        printSolutions();
    }

    void printSolutions()
    {
        for (int k = 0; k < solutions.size(); k++)
        {
            cout << "No. " << k + 1 << endl;

            // 先按列打印
            for (int j = 0; j < N; j++)
            { // 遍历列
                for (int i = 0; i < N; i++)
                { // 遍历行
                    cout << (solutions[k][i] == j ? "1" : "0");
                    if (i < N - 1)
                        cout << " ";
                }
                cout << endl;
            }
        }
    }
};

int main()
{
    EightQueens queens;
    queens.findAllSolutions();
    return 0;
}
