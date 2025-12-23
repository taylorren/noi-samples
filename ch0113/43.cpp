#include <iostream>
#include <vector>

using namespace std;

// 判断是否为闰年
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 计算两个月份之间的天数差
int daysBetweenMonths(int year, int month1, int month2)
{
    int days = 0;
    if (month1 > month2)
    {
        swap(month1, month2);
    }
    for (int month = month1; month < month2; ++month)
    {
        if (month == 2)
        { // 二月
            days += isLeapYear(year) ? 29 : 28;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        { // 30天的月份
            days += 30;
        }
        else
        { // 31天的月份
            days += 31;
        }
    }
    return days;
}

int main()
{
    int n;
    cin >> n; // 读取输入的行数
    vector<string> results;

    for (int i = 0; i < n; ++i)
    {
        int year, month1, month2;
        cin >> year >> month1 >> month2; // 读取年份和两个月份

        // 计算两个月份之间的天数差
        int daysDiff = daysBetweenMonths(year, month1, month2);

        // 判断是否相关
        if (daysDiff % 7 == 0)
        {
            results.push_back("YES");
        }
        else
        {
            results.push_back("NO");
        }
    }

    // 输出结果
    for (const string &result : results)
    {
        cout << result << endl;
    }

    return 0;
}
