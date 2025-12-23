#include <bits/stdc++.h>
using namespace std;

const int MAX = 110;

struct student
{
    string name;
    int average;
    int class_review;
    char cadre;
    char west;
    int articles;
    int scholarship;
};

int calculate(student s)
{
    int sum = 0;

    if (s.average > 80&&s.articles>=1)
    {
        sum += 8000;
    }

    if (s.average > 85 && s.class_review > 80)
    {
        sum += 4000;
    }

    if (s.average > 90)
    {
        sum += 2000;
    }

    if (s.average > 85 && s.west == 'Y')
    {
        sum += 1000;
    }

    if (s.class_review > 80 && s.cadre == 'Y')
    {
        sum += 850;
    }

    return sum;
}

int main()
{
    int n;
    cin >> n;

    student students[MAX];
    for (int i = 1; i <= n; i++)
    {
        string name;
        int average;
        int class_review;
        char cadre;
        char west;
        int articles;

        cin >> name >> average >> class_review >> cadre >> west >> articles;
        students[i].name = name;
        students[i].average = average;
        students[i].class_review = class_review;
        students[i].cadre = cadre;
        students[i].west = west;
        students[i].articles = articles;

        students[i].scholarship = calculate(students[i]);
    }

    int total_scholarship=0;
    int highest=-100;
    string name="";

    for(int i=1;i<=n;i++)
    {
        int tmp=students[i].scholarship;
        total_scholarship+=tmp;

        if(tmp>highest)
        {
            highest=tmp;
            name=students[i].name;
        }
    }

    cout<<name<<endl<<highest<<endl<<total_scholarship<<endl;

    return 0;
}
