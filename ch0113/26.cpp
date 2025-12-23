#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	string s[505];
	//
	int cnt = 0;
	for (int i = 0; i < str.size() - n + 1; i++)
	{
		s[i] = str.substr(i, n);
		cnt = i + 1; // 读入的字符串个数
	}
	map<string, int> mp;
	int ans = 0;
	for (int i = 0; i < cnt; i++)
	{
		mp[s[i]] = 0;
	} // 初始化
	for (int i = 0; i < cnt; i++)
		mp[s[i]]++;
	for (int i = 0; i < cnt; i++)
	{
		ans = max(ans, mp[s[i]]);
	}
	if (ans <= 1)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << ans << endl;
	for (int i = 0; i < cnt; i++)
	{
		if (mp[s[i]] == ans)
		{
			cout << s[i] << endl;
			mp[s[i]] = 0;
		}
	}
	return 0;
}
