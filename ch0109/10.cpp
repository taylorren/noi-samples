#include <bits/stdc++.h>
using namespace std;

const int MAX_ROWS=31;
const int MAX_COLS=101;

void fill_numbers_in_row(int i, string s, unsigned int numbers[MAX_ROWS][MAX_COLS])
{
    istringstream iss(s);
    int n;
    char c;
    int col=1;
    numbers[i][0]=0;

    while(iss>>n)
    {
        numbers[i][col]=n;
        if(n>numbers[i][0])
        {
            numbers[i][0]=n;
        }

        col++;
        iss>>c;


    }
}

int main()
{
    int n;
    cin>>n;
    unsigned int numbers[MAX_ROWS][MAX_COLS];

    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        fill_numbers_in_row(i, s, numbers);
    }

    unsigned int max=0;
    for(int i=1;i<=n;i++)
    {
        if(numbers[i][0]>max)
        {
            max=numbers[i][0];
        }
    }

    cout<<max<<endl;
    ostringstream oss;
    for(int i=1;i<=n;i++)
    {
        if(numbers[i][0]==max)
        {
            oss<<i<<",";
        }
    }
    string out=oss.str();
    out=out.substr(0, out.length()-1);
    cout<<out<<endl;

    return 0;
}
