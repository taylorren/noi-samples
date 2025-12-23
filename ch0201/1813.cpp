#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 6;

// 原始灯的状态
int lights[ROWS][COLS];
// 按钮的状态（是否按下）
int buttons[ROWS][COLS];
// 当前灯的状态（会随着按钮的改变而改变）
int currentLights[ROWS][COLS];

// 按下按钮时改变灯的状态
void pressButton(int row, int col)
{
    // 改变当前位置的灯
    currentLights[row][col] = !currentLights[row][col];

    // 改变上方的灯
    if (row > 0)
        currentLights[row - 1][col] = !currentLights[row - 1][col];

    // 改变下方的灯
    if (row < ROWS - 1)
        currentLights[row + 1][col] = !currentLights[row + 1][col];

    // 改变左边的灯
    if (col > 0)
        currentLights[row][col - 1] = !currentLights[row][col - 1];

    // 改变右边的灯
    if (col < COLS - 1)
        currentLights[row][col + 1] = !currentLights[row][col + 1];
}

// 检查是否所有灯都熄灭
bool allLightsOff()
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (currentLights[i][j])
                return false;
    return true;
}

// 复制灯的状态
void copyLights()
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            currentLights[i][j] = lights[i][j];
}

int main()
{
    // 读入初始状态
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            cin >> lights[i][j];

    // 尝试第一行的所有可能按钮组合
    for (int state = 0; state < (1 << COLS); state++)
    {
        // 重置按钮状态和当前灯状态
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                buttons[i][j] = 0;

        copyLights();

        // 设置第一行的按钮
        for (int j = 0; j < COLS; j++)
        {
            if (state & (1 << j))
            {
                buttons[0][j] = 1;
                pressButton(0, j);
            }
        }

        // 根据上一行的灯状态决定当前行的按钮
        for (int i = 1; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (currentLights[i - 1][j])
                {
                    buttons[i][j] = 1;
                    pressButton(i, j);
                }
            }
        }

        // 如果找到解，输出并退出
        if (allLightsOff())
        {
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    cout << buttons[i][j];
                    if (j < COLS - 1)
                        cout << " ";
                }
                cout << endl;
            }
            break;
        }
    }

    return 0;
}
