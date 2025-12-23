#include <iostream>

using namespace std;

int main()
{
    int a1, a2, n;
    cin>>a1>>a2>>n;

    int d=a2-a1;

    int final=a1+d*(n-1);
    cout<<final<<endl;
    return 0;
}

