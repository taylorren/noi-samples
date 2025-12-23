#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;

struct Student
{
    string name;
    int score;
};

bool cmp(Student& a, Student& b)
{
    if(a.score != b.score)
    {
        return a.score > b.score;
    }
    else
    {
        return a.name < b.name;
    }
}

int main()
{
    int n;
    cin >> n;

    Student students[MAX];

    for(int i = 1; i <= n; i++)
    {
        string name;
        int score;
        cin >> name >> score;

        Student s;
        s.name = name;
        s.score = score;
        students[i] = s;
    }

    sort(students + 1, students + n + 1, cmp);
    for(int i = 1; i <= n; i++)
    {
        cout << students[i].name << " " << students[i].score << endl;
    }

    return 0;
}