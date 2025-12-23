#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	map<int, int> numbers = {};
	for (int i = 1; i <= n; i++)
	{
		int number;
		cin >> number;
		numbers[number]++;
	}

	bool exist = false;
	for (auto &nn : numbers)
	{
		if (n % 2 == 1)
		{
			if (nn.second >= n / 2 + 1)
			{
				cout << nn.first << endl;
				exist = true;
				break;
			}
		}
		else
		{
			if(nn.second>n/2)
			{
				cout<<nn.first<<endl;
				exist=true;
				break;
			}
		}
	}
	if (!exist)
	{
		cout << "no" << endl;
	}
	return 0;
}