#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int cocktail_total, cocktail_success;
    cin>>cocktail_total>>cocktail_success;
    float cocktail_rate=1.*cocktail_success/cocktail_total;

    int method_total, method_success;
    for(int i=1;i<n;i++)
    {
        cin>>method_total>>method_success;
        float rate=1.*method_success/method_total;

        if(rate-cocktail_rate>0.05)
        {
            cout<<"better"<<endl;
        }
        else if (cocktail_rate-rate>0.05)
        {
            cout<<"worse"<<endl;
        }
        else 
        {
            cout<<"same"<<endl;
        }
    }
}
