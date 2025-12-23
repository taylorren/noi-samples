#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int len=s.length();

    int count=0;

    for(int i=0;i<=len-1;i++){
        char c=s[i];
        if(c>='0'&&c<='9')
        {
            count++;
        }
    }

    cout<<count<<endl;
    return 0;
}
