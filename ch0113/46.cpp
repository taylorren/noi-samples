#include <bits/stdc++.h>
using namespace std;

int main()
{
	string  m;
	cin>>m;

	int len=m.length();
	int result=0;

	for(int i=0;i<len;i++)
	{
		int c=m[i]-'0';
		result=result*8+c;
	}
	cout<<result;
}
