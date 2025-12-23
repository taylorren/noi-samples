#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int cnt = 0;
	char c;
	for (int i = 0; i < str.size(); i++)
	{
		// 第一类双指针算法
		int j = i;
		while (j < str.size() && str[j] == str[i])
		{
			j++;
		}
		if (j - i > cnt)
		{
			cnt = j - i;
			c = str[i];
		}
		i = j - 1;
	}
	cout << c << ' ' << cnt << endl;
}