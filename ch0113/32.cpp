#include<bits/stdc++.h>
using namespace std;

bool is_leap(int n)
{
    return ((n%4==0 && n%100!=0) || n%400==0);
}


int main()
{
    string str[]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
    int n;
    cin >> n;
    int year=2000,month=1,day=1;
    int a[]={31,29,31,30,31,30,31,31,30,31,30,31};
 
    int ans;   //判断星期几
    ans=(1+n)%7-1;
    if(ans==-1)
        ans=6;
    //date
    while(n>0)
    {
        int flag=1;
        int i;
        for(i=0;i<12;i++)
        {
            if(n<a[i])
            {
                flag=0;
                break;
            }
            else
                n-=a[i];
        }
        if(flag)
        {            //走过1年
            year++;
            if(!is_leap(year))   //注意这里修改2月份的天数
                a[1]=28;
            else
                a[1]=29;   
        }
        else{
            month=i+1;
            day=day+n;
            break;
        }
    }
    printf("%d-%02d-%02d",year,month,day);
    cout << " " << str[ans];
    return 0;
}

