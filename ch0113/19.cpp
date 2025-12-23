#include <bits/stdc++.h>
using namespace std;

struct Loc
{
    int qty, distance;
    int clockwise_dist, counter_clockwise_dist;
};

int main()
{
    Loc locations[10000];
    int total_dist = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int qty, dist;
        cin >> qty >> dist;
        total_dist += dist;

        locations[i].qty = qty;
        locations[i].distance = dist;
    }

    locations[0].clockwise_dist = 0;
    locations[0].counter_clockwise_dist = 0;

    int inter_dist_clock = 0;
    int inter_dist_counter = 0;
    int max = 1e9;

    for (int i = 1; i < n; i++)
    {
        inter_dist_clock += locations[i-1].distance;
        inter_dist_counter += total_dist - inter_dist_clock;

        locations[i].clockwise_dist = inter_dist_clock;
        locations[i].counter_clockwise_dist = inter_dist_counter;
    }

    int station_pos;
    for (int i = 0; i < n; i++)
    {
        int j = i + 1, cost = 0, temp;
        int k = n - 1;

        while (k)
        {
            if (j == n)
            {
                j = 0;
            }
            temp = abs(locations[j].clockwise_dist - locations[i].clockwise_dist);
            if (total_dist - temp < temp)
            {
                temp = total_dist - temp;
            }

            cost += temp * locations[j].qty;
            j++;
            if (j == n)
            {
                j = 0;
            }
            k--;
        }
        if(cost<max)
        {
            max=cost;
            station_pos=i;
        }
    }

    cout<<station_pos<<","<<max;
    return 0;
}