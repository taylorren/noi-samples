#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> numbers;
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        numbers.insert(tmp);
    }

    for(auto& e:numbers)
    {
        cout<<e<<" ";
    }
    
    cout<<endl;
    return 0;
}
