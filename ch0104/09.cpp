#include <iostream>

using namespace std;

int main()
{
    int x;
    cin>>x;
    bool print_n=true;

    if(x%3==0)
    {
        cout<<"3 ";
        print_n=false;
    }

    if(x%5==0)
    {
        cout<<"5 ";
        print_n=false;
    }

    if(x%7==0)
    {
        cout<<"7";
        print_n=false;
    }
    if(print_n) 
    {
        cout<<"n";
    }

    
    return 0;
}
