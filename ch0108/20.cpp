#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    char letters[250];
    char output[250][250];

    cin>>letters;

    int length=strlen(letters);
    int rows=length/n;
    int index=0;

    for(int i=0;i<rows;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<n;j++)
            {
                output[i][j]=letters[index];
                index++;
            }
        }
        else 
        {
            for(int j=n-1;j>=0;j--)
            {
                output[i][j]=letters[index];
                index++;
            }
        }
    }

    for(int j=0;j<n;j++)
    {
        for(int i=0;i<rows;i++)
        {
            cout<<output[i][j];
        }
    }
    return 0;
}