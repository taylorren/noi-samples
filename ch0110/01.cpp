#include <bits/stdc++.h>
using namespace std;

const int MAX=105;

struct student 
{
    string id;
    float score;
};

bool cmp(student &a, student &b)
{
    return a.score>b.score;
}

int main()
{
    int n, rank;
    cin>>n>>rank;

    vector<student> students;

    for(int i=1;i<=n;i++)
    {
        string tmp;
        float s;
        cin>>tmp>>s;

        student stu;
        stu.id=tmp;
        stu.score=s;

        students.push_back(stu);    
    }

    sort(students.begin(), students.end(), cmp);
    student stu_rank=students.at(rank-1);
    cout<<stu_rank.id<<" ";
    printf("%g\n", stu_rank.score);
    
    return 0;
}
