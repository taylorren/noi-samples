#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
#include<iomanip>
#include<set>
#include<queue>
#include<stack> 
#include<map>
using namespace std;
string  c;
int n,a[100000];//a数组记录每次c字符串的长度
int main()
{
	cin >> n;
	c = "1234567"; a[0] = 4 ,a[1] = 3;//因为c由1234567这几个字符组成，a[0],a[1]就是a，b的字符数
	for (int i = 2; i < 10000; i++)
	{
		a[i] = a[i - 1] + a[i - 2];//相当于把每次c的长度求出来
	}
	while (n > 7)//当长度大于7就要
	{
		int i = 0;
		while (a[i] < n)//直到找到c的长度大于n
			i++;
		n = n - a[i-1];//这个地方为什么这样就能得到答案了，我也不太理解
	}
	cout << c[n-1];
}

//https://blog.csdn.net/Q210617/article/details/131934618