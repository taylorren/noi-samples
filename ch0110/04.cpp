#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;

struct Student
{
    int chinese;
    int maths;
    int english;
    int id;

    int get_total()
    {
        return chinese + maths + english;
    }
};

bool cmp(Student &a, Student &b)
{
    if (a.get_total() == b.get_total())
    {
        if (a.chinese == b.chinese)
        {
            return a.id < b.id;
        }
        else
        {
            return a.chinese > b.chinese;
        }
    }
    else
    {
        return a.get_total() > b.get_total();
    }
}

int main()
{
    int n;
    cin >> n;

    vector<Student> students;

    for (int i = 1; i <= n; i++)
    {
        int c, m, e;
        cin>>c>>m>>e;

        Student s;
        s.chinese=c;
        s.maths=m;
        s.english=e;
        s.id=i;

        students.push_back(s);
    }

    sort(students.begin(), students.end(), cmp);

    for(int i=0;i<=4;i++)
    {
        Student s=students[i];
        cout<<s.id<<" "<<s.get_total()<<endl;
    }
    
    return 0;
}
