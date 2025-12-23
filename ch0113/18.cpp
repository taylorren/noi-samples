#include <bits/stdc++.h>
using namespace std;

int main()
{
    int year, month, day;
    char a, b;
    cin >> year >> a >> month >> b >> day;
    bool leap = false;    // 这个用来判断闰年，之前有题目写了这个，这里不多说
    bool special = false; // 这里标记输入天数是否跨月，跨年，因为那些要特殊处理，其他的只要天数加1就好
    if (year % 4 == 0 & year % 100 != 0)
        leap = true;
    if (year % 400 == 0)
        leap = true;
    if (month == 2)
    { // 对二月进行处理，注意闰年
        if (leap == true && day == 29)
        {
            month++;
            day = 1;
            special = true;
        }
        if (leap == false && day == 28)
        {
            month++;
            day = 1;
            special = true;
        }
    }
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day == 31))
    { // 对大月进行处理
        if (month == 12)
        { // 其中12月跨年，单独处理
            month = 1;
            day = 1;
            year++;
            special = true;
        }
        else
        { // 其他的跨月
            day = 1;
            month++;
            special = true;
        }
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30)
    { // 然后对小月进行处理
        day = 1;
        month++;
        special = true;
    }
    if (special == false) // 对不特殊的进行处理
        day++;
    cout << year << '-' << setw(2) << setfill('0') << month << '-' << setw(2) << setfill('0') << day << endl; // 其中setw（）设置输出宽度，setfill（）用来进行填补宽度。
    return 0;
}