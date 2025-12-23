#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin>>str;

	int len=str.length();
	map<char, int> mapping={};
	for(int i=0;i<len;i++)
	{
		mapping[str[i]]++;
	}

	int max_count=-1;
	char c;
	for(auto &m:mapping)
	{
		if(m.second>max_count)
		{
			max_count=m.second;
			c=m.first;
		}
		else if(m.second==max_count)
		{
			if(c>m.first)
			{
				c=m.first;
			}
		}
	}

	cout<<c<<" "<<max_count;

	return 0;
}