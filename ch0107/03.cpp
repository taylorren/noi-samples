#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    float gauge;
    cin>>gauge;

    string dna1, dna2;
    cin>>dna1>>dna2;

    int len=dna1.length();
    int count=0;

    for(int i=0;i<len;i++)
    {
        if(dna1[i]==dna2[i])
        {
            count++;
        }
    }

    if(count*1.0/len>=gauge)
    {
        cout<<"yes"<<endl;
    }
    else 
    {
        cout<<"no"<<endl;
    }

    return 0;
}
