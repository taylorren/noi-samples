#include <iostream>
#include <iomanip>
using namespace std;

void line(int width, char c, int f)
{
    cout<<c;
    char fc;
    if(f==0) //空心
    {
        fc=' ';
    }
    else 
    {
        fc=c;
    }

    for(int i=2;i<width;i++)
    {
        cout<<fc;
    }

    cout<<c;
    cout<<endl;
}

int main()
{
    int height, width, fill;
    char c;
    cin>>height>>width>>c>>fill;
    line(width, c, 1);
    for(int i=2;i<height;i++)
    {
        line(width, c, fill);
    }
    line(width, c, 1);

    return 0;
}
