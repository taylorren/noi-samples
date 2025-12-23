#include <iostream>

using namespace std;

int main()
{
    int d;
    cin>>d;

    float walk, bike;
    walk=d/1.2;
    bike=d/3.0+27+23;

    if(walk>bike)
    {
        cout<<"Bike"<<endl;
    }
    else if (walk==bike)
    {
        cout<<"All"<<endl;
    }
    else 
    {
        cout<<"Walk"<<endl;
    }

    return 0;
}
