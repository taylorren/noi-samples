#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct Student
{
    string name;
    int month;
    int day;
};

// 按照名字长度和字典序排序
bool compareNames(const string& a, const string& b)
{
    if(a.length() != b.length())
    {
        return a.length() < b.length();
    }
    return a < b;
}

int main()
{
    int n;
    cin >> n;

    vector<Student> students(n);
    map<pair<int, int>, vector<string>> birthdays;

    // 读取学生信息
    for(int i = 0; i < n; i++)
    {
        cin >> students[i].name >> students[i].month >> students[i].day;
        birthdays[{students[i].month, students[i].day}].push_back(
            students[i].name);
    }

    // 检查是否有相同生日的学生
    bool hasSameBirthday = false;

    // 按日期顺序输出
    for(auto& entry : birthdays)
    {
        if(entry.second.size() > 1)
        {
            hasSameBirthday = true;

            // 按要求排序名字
            sort(entry.second.begin(), entry.second.end(), compareNames);

            // 输出月和日
            cout << entry.first.first << " " << entry.first.second;

            // 输出所有在当天出生的学生的名字
            for(const string& name : entry.second)
            {
                cout << " " << name;
            }
            cout << endl;
        }
    }

    // 如果没有生日相同的学生，输出"None"
    if(!hasSameBirthday)
    {
        cout << "None" << endl;
    }

    return 0;
}