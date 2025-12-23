#include <bits/stdc++.h>
using namespace std;

bool cmp1(int &a, int &b)
{
    return a > b;
}

bool cmp2(int &a, int &b)
{
    return a < b;
}

int main()
{
    vector<int> even;
    vector<int> odd;

    for(int i=1;i<=10;i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp%2==0)
        {
            even.push_back(tmp);
        }
        else
        {
            odd.push_back(tmp);
        }
    }
    
    sort(odd.begin(), odd.end(), cmp1);
    sort(even.begin(), even.end(), cmp2);

    for(auto& e:odd)
    {
        cout<<e<<" ";
    }

    for(auto& e:even)
    {
        cout<<e<<" ";
    }
    cout<<endl;
    
    return 0;
}
