#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, multiset<int>> sequences;
    int n;
    cin >> n;

    while (n--)
    {
        string command;
        cin >> command;

        if (command == "new")
        {
            int id;
            cin >> id;
            sequences[id]; // Create an empty multiset for id if it doesn't exist
        }
        else if (command == "add")
        {
            int id, num;
            cin >> id >> num;
            sequences[id].insert(num); // Insert the number into the multiset
        }
        else if (command == "merge")
        {
            int id1, id2;
            cin >> id1 >> id2;
            if (id1 != id2)
            {
                sequences[id1].insert(sequences[id2].begin(), sequences[id2].end());
                sequences[id2].clear(); // Clear the second sequence after merging
            }
        }
        else if (command == "unique")
        {
            int id;
            cin >> id;
            unordered_set<int> unique_elements(sequences[id].begin(), sequences[id].end());
            sequences[id] = multiset<int>(unique_elements.begin(), unique_elements.end()); // Reassign unique elements
        }
        else if (command == "out")
        {
            int id;
            cin >> id;
            for (auto it = sequences[id].begin(); it != sequences[id].end(); ++it)
            {
                if (it != sequences[id].begin())
                    cout << " ";
                cout << *it;
            }
            cout << endl;
        }
    }

    return 0;
}
