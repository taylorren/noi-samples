#include <bits/stdc++.h>
using namespace std;

const int MAX=500;

float find_diff(float effects[MAX], int n, float average, float min, float max)
{
    float diff_max=-1;
    bool min_flagged=false;
    bool max_flagged=false;

    for(int i=1;i<=n;i++)
    {
        if(effects[i]==min&&!min_flagged)
        {
            min_flagged=true;
            continue;
        }
        if(effects[i]==max&&!max_flagged)
        {
            max_flagged=true;
            continue;
        }
        float tmp=abs(average-effects[i]);
        if(tmp>diff_max)
        {
            diff_max=tmp;
        }
    }
    return diff_max;
}

int main()
{
    float effects[MAX];
    int n;
    cin>>n;

    float min=1e9, max=-1e9;
    float sum=0.0;

    for(int i=1;i<=n;i++)
    {
        float tmp;
        cin>>tmp;
        if(tmp>max)
        {
            max=tmp;
        }
        if(tmp<min)
        {
            min=tmp;
        }
        sum+=tmp;
        effects[i]=tmp;
    }

    float average=(sum-max-min)/(n-2);
    float diff=find_diff(effects, n, average, min, max);
    
    cout<<fixed<<setprecision(2)<<average<<" "<<diff<<endl;
    return 0;
}
