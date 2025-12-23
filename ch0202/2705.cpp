#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

void checkBrackets(char* str)
{
    int len = strlen(str);
    char mark[101]; // 用于标记不匹配的括号
    memset(mark, ' ', sizeof(mark));
    mark[len] = '\0';

    stack<int> leftBrackets; // 存储左括号的位置

    // 第一遍扫描，处理匹配的括号
    for(int i = 0; i < len; i++)
    {
        if(str[i] == '(')
        {
            leftBrackets.push(i);
        }
        else if(str[i] == ')')
        {
            if(!leftBrackets.empty())
            {
                // 找到匹配的左括号，不做标记
                leftBrackets.pop();
            }
            else
            {
                // 没有匹配的左括号，标记为?
                mark[i] = '?';
            }
        }
    }

    // 处理剩余未匹配的左括号，标记为$
    while(!leftBrackets.empty())
    {
        mark[leftBrackets.top()] = '$';
        leftBrackets.pop();
    }

    // 输出结果
    cout << str << endl;
    cout << mark << endl;
}

int main()
{
    char str[101];

    // 逐行读取输入直到EOF
    while(cin.getline(str, 101))
    {
        checkBrackets(str);
    }

    return 0;
}