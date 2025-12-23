#include <bits/stdc++.h>
using namespace std;

struct Patient
{
    string id;
    int age;
    int index;
};

bool cmp(Patient &a, Patient &b)
{
    if (a.age >= 60 && b.age >= 60)
    {
        if (a.age != b.age)
        {
            return a.age>b.age;
        }
        else
        {
            return a.index<b.index;
        }
    }
    else if (a.age >= 60 && b.age < 60)
    {
        return true;
    }
    else if (a.age < 60 && b.age >= 60)
    {
        return false;
    }
    else
    {
        return a.index < b.index;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<Patient> patients;
    for (int i = 1; i <= n; i++)
    {
        string id;
        int age;
        cin >> id >> age;

        Patient p;
        p.id = id;
        p.age = age;
        p.index=i;

        patients.push_back(p);
    }

    sort(patients.begin(), patients.end(), cmp);

    for (auto &p : patients)
    {
        cout << p.id << endl;
    }
    return 0;
}
