#include <iostream>

using namespace std;

int main()
{
    int x, y;
    char op;
    cin>>x>>y>>op;

    if(op=='+')
    {
        cout<<x+y<<endl;
    }
    else if(op=='-')
    {
        cout<<x-y<<endl;
    }
    else if(op=='*')
    {
        cout<<x*y<<endl;
    }
    else if (op=='/')
    {
        if(y==0){
            cout<<"Divided by zero!"<<endl;
        }
        else 
        {
            cout<<x/y<<endl;
        }
    }
    else 
    {
        cout<<"Invalid operator!"<<endl;
    }
    return 0;
}
