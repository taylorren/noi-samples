#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    while(true) {
        cin >> n >> k;
        if(n == 0 && k == 0) break;
        
        queue<int> q;
        for(int i = 1; i <= n; i++)
        {
            q.push(i);
        }

        while(q.size() != 1)
        {
            for(int i = 1; i < k; i++)
            {
                q.push(q.front());
                q.pop();
            }
            
            q.pop();
        }
        cout << q.front() << endl;
    }
    return 0;
}