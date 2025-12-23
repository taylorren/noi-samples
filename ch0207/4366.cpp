#include <bits/stdc++.h>
using namespace std;

const int maxn=200005;

long long n,k,p;
long long col,pri;
long long aft[maxn],tot[maxn],numb[maxn],bef;

long long ans;

int main()
{
    cin>>n>>k>>p;
    
    for (int i=1;i<=n;++i) {
        cin>>col>>pri;
        
        // 如果当前咖啡店价格不超过预算，更新最近的可行咖啡店位置
        if (pri<=p) {
            bef=i;
        }
        
        // 如果最近的可行咖啡店在上一个同色调客栈之后，
        // 说明之间有合适的咖啡店，可以更新可行配对数
        if (bef>=aft[col]) {
            tot[col]=numb[col];
        }
        
        // 当前客栈可以和之前tot[col]个可行的同色调客栈配对
        ans+=tot[col];
        
        // 更新当前色调的最后出现位置
        aft[col]=i;
        
        // 更新当前色调的出现次数
        numb[col]++;
    }
	
	cout<<ans; // 输出答案

	return 0;
}