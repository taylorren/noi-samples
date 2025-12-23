#include <bits/stdc++.h>
using namespace std;

const int RIGHT = 0;
const int DOWN = 1;
const int LEFT = 2;
const int UP = 3;

const int MAX = 1000;

string mapping[27] = {
    "00000", // space
    "00001", // A
    "00010", // B
    "00011", // C
    "00100", // D
    "00101", // E
    "00110", // F
    "00111", // G
    "01000", // H
    "01001", // I
    "01010", // J
    "01011", // K
    "01100", // L
    "01101", // M
    "01110", // N
    "01111", // O
    "10000", // P
    "10001", // Q
    "10010", // R
    "10011", // S
    "10100", // T
    "10101", // U
    "10110", // V
    "10111", // W
    "11000", // X
    "11001", // Y
    "11010", // Z
};

void spiral(string res, char output[MAX][MAX], int rows, int cols)
{
    int MAX_ROW = rows;
    int MAX_COL = cols;
    int MIN_ROW = 1;
    int MIN_COL = 1;

    int direction = RIGHT;
    int row = 1, col = 1;
    for (int index = 0; index < rows * cols; index++)
    {
        char c=res[index];
        output[row][col] = c;

        switch (direction)
        {
        case RIGHT:
            col++;
            if (col > MAX_COL)
            {
                direction = DOWN;
                col--;
                row++;
                MIN_ROW++;
            }
            break;
        case DOWN:
            row++;
            if (row > MAX_ROW)
            {
                direction = LEFT;
                row--;
                col--;
                MAX_COL--;
            }
            break;
        case LEFT:
            col--;
            if (col < MIN_COL)
            {
                direction = UP;
                col++;
                row--;
                MAX_ROW--;
            }
            break;
        case UP:
            row--;
            if (row < MIN_ROW)
            {
                direction = RIGHT;
                row++;
                col++;
                MIN_COL++;
            }
            break;
        default:
            break;
        }
    }
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;
    cin.ignore();
    string s;
    getline(cin, s);

    string res;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        string tmp;
        tmp = (c == ' ') ? mapping[0] : mapping[c - 'A' + 1];
        res += tmp;
    }

    while (res.length() < rows * cols) // 用"0"填充
    {
        res += "0";
    }
    
    char output[MAX][MAX];
    spiral(res, output, rows, cols);

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            cout << output[i][j];
        }
    }

    return 0;
}
