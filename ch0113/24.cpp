#include <bits/stdc++.h>
#include <chrono>

using namespace std;

bool is_leap(int y)
{
    return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}

int get_day_in_month(int y, int m)
{
    int day;
    if (m == 2)
    {
        day = is_leap(y) ? 29 : 28;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        day = 30;
    }
    else
    {
        day = 31;
    }
    return day;
}

int get_days(int y, int m)
{
    int d = 0;
    for (int i = 1900; i < y; i++)
    {
        d += is_leap(i) ? 366 : 365;
    }
    for (int i = 1; i < m; i++)
    {
        d += get_day_in_month(y, i);
    }
    return d;
}

int main()
{
    int y, m;
    cin >> y >> m;

    int weekday = (get_days(y, m) + 1) % 7;
    cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;

    for (int i = 0; i < weekday; i++)
    {
        cout << "    ";
    }

    int days = get_day_in_month(y, m);
    for(int i=1;i<=days;i++)
    {
        cout<<setw(3)<<i<<' ';
        weekday++;
        if(weekday==7)
        {
            weekday=0;
            cout<<endl;
        }
    }

    return 0;
}
