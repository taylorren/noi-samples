#include <bits/stdc++.h>
using namespace std;

const int MAX=501;

bool cmp(int &a, int &b)
{
    return a<b;
}

int main()
{
    int n;
    cin>>n;

    vector<int> numbers;

    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;

        if(tmp%2==1)
        {
            numbers.push_back(tmp);
        }
    }

    sort(numbers.begin(), numbers.end(), cmp);
    ostringstream oss;

    for(int e:numbers)
    {
        oss<<e<<",";
        
    }
    string out=oss.str();
    out=out.substr(0, out.length()-1);
    cout<<out<<endl;

    return 0;
}
