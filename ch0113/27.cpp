#include <bits/stdc++.h>
using namespace std;

const int N = 410;
int main()
{
	string a;
	int as[N], yu, lena, ans[N], tot = 0;

	cin >> a;
	lena = a.size();
	for (int i = 0; i < lena; i++)
		as[i] = a[i] - '0';
	for (int i = 0; i < lena; i++)
	{
		ans[++tot] = (yu * 10 + as[i]) / 13;
		yu = (yu * 10 + as[i]) % 13;
	}
	int l = 1;
	while (ans[l] == 0 && l < tot)
		l++;
	for (int i = l; i <= tot; i++)
		cout << ans[i];
	cout << endl
		 << yu << endl;
}