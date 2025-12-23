#include <bits/stdc++.h>
using namespace std;

const int M = 101;
const int N = 10001;

struct Room
{
    int has_ladder;
    int partial_key;
    // Helper to display the struct
    string get_string()
    {
        ostringstream oss;
        oss << "Ladder: " << has_ladder << " Partial: " << partial_key;
        return oss.str();
    }
};

Room rooms[N][M];

void log(string msg)
{
    cout << msg << endl;
}

int find_next_entry_in_this_level(int level, int count, int entry, int m)
{
    // cout<<"---------------------"<<endl;
    // cout<<"Count: "<<count<<endl;

    int total_ladders=0;
    for(int j=0;j<m;j++)
    {
        total_ladders+=rooms[level][j].has_ladder;
    }
    count%=total_ladders;
    if(count==0)
    {
        count=total_ladders;
    }

    while (count > 0)
    {
        if (rooms[level][entry].has_ladder)
        {
            count--;
            if(count==0)
            {
                break;
            }
        }
        entry = (entry + 1) % m;
    }

    // ostringstream oss;
    // oss << "Level: " << level<<" Next Entry: "<<entry;
    // log(oss.str());

    return entry;
}

int find_password(int entry, int n, int m)
{
    int key = 0;

    for (int level = 1; level <= n; level++)
    {
        key = (key+rooms[level][entry].partial_key)%20123;
        int count = rooms[level][entry].partial_key;
        entry = find_next_entry_in_this_level(level, count, entry, m);
    }

    return key;
}

int main()
{
    int n, m;
    int key;

    cin >> n >> m; // n层楼，每层楼m个房间

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            Room r;
            cin >> r.has_ladder >> r.partial_key;
            rooms[i][j] = r;
        }
    }

    int entry;
    cin >> entry;

    key = find_password(entry, n, m);
    cout<<key<<endl;

    return 0;
}