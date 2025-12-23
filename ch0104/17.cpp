#include <iostream>

using namespace std;

int main()
{
    int year;
    cin>>year;
    char res;

    if(year%4!=0)
    {
        res='N';
    } 
    else if (year%100!=0)
    {
        res='Y';
    } 
    else if (year%400!=0)
    {
        res='N';
    }
    else 
    {
        res='Y';
    }
    cout<<res<<endl;
    return 0;
}
