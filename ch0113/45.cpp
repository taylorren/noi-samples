#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m;
	cin>>m;

	string oct;
	while(m>0)
	{
		int r=m%8;
		oct=to_string(r)+oct;
		m/=8;
	}
	cout<<oct<<endl;
}