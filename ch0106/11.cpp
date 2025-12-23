#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 220;

void reverse(string &str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
    {
        swap(str[i], str[n - i - 1]);
    }
}

string calculate(string a, string b)
{
    reverse(a);
    a.resize(MAX, '0');
    reverse(a);
    reverse(b);
    b.resize(MAX, '0');
    reverse(b);

    string result;
    int digit_a, digit_b, borrow = 0;
    for (int i = MAX - 1; i >= 0; i--)
    {

        digit_a = a[i] - '0';
        digit_b = b[i] - '0';
        int tmp=digit_a-borrow-digit_b;
        if(tmp<0)
        {
            tmp+=10;
            borrow=1;
        }
        else{
            borrow=0;
        }
        result.insert(0,1,tmp+'0');
    }

    while(result[0]=='0')
    {
        result.erase(0,1);
    }
    
    if(result.length()==0)
    {
        result="0";
    }
    return result;
}

int main()
{
    string a, b;
    cin >> a >> b;
    string res=calculate(a, b);
    cout<<res<<endl;

    return 0;
}
