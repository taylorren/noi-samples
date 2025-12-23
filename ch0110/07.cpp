#include <bits/stdc++.h>
using namespace std;

bool ascend(float &a, float &b)
{
    return a<b;
}

bool descend(float &a, float &b)
{
    return a>b;
}

int main()
{
    int n;
    cin>>n;

    vector<float> males;
    vector<float> females;

    for(int i=1;i<=n;i++)
    {
        string gender; 
        float h;

        cin>>gender>>h;

        if(gender=="male")
        {
            males.push_back(h);
        }
        else 
        {
            females.push_back(h);
        }
    }
    sort(males.begin(), males.end(), ascend);
    sort(females.begin(), females.end(), descend);

    cout<<fixed<<setprecision(2);

    for(auto& m:males)
    {
        cout<<m<<" ";
    }
    for(auto& f:females)
    {
        cout<<f<<" ";
    }
    cout<<endl;

    return 0;
}
