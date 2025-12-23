#include <bits/stdc++.h>
using namespace std;

struct Haab
{
    string name;
    int day;
};

const Haab haab_cal[19] =
    {
        {"pop", 0}, {"no", 20}, {"zip", 40}, {"zotz", 60}, {"tzec", 80}, {"xul", 100}, 
        {"yoxkin", 120}, {"mol", 140}, {"chen", 160}, {"yax", 180}, {"zac", 200}, {"ceh", 220}, 
        {"mac", 240}, {"kankin", 260}, {"muan", 280}, {"pax", 300}, {"koyab", 320}, {"cumhu", 340}, 
        {"uayet", 360}
    };

const string Tzo_Day[20] = {
    "imix", "ik", "akbal", "kan", "chicchan",
    "cimi", "manik", "lamat", "muluk", "ok",
    "chuen", "eb", "ben", "ix", "mem",
    "cib", "caban", "eznab", "canac", "ahau"};

int main()
{
    int count;
    cin >> count;

    float haab_d;
    string haab_m;
    int haab_y;

    string res;

    for (int i = 1; i <= count; i++)
    {
        int tzo_d;
        int tzo_y;
        string tzo_m;

        cin >> haab_d >> haab_m >> haab_y;

        //找到哪个Haab月
        for(int h=0;h<19;h++)
        {
            if(haab_cal[h].name==haab_m)
            {
                int tmp_d=haab_cal[h].day+(int)haab_d+haab_y*365;
                tzo_d=tmp_d%13+1;
                tzo_m=Tzo_Day[tmp_d%20];
                tzo_y=tmp_d/260;

                ostringstream oss;
                oss<<tzo_d<<" "<<tzo_m<<" "<<tzo_y<<endl;
                res+=oss.str();
            }
        }
    }

    cout<<count<<endl;
    cout<<res<<endl;

    return 0;
}
