#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> elements; // 记录元素及其数量
    unordered_map<int, bool> added;   // 记录元素是否曾被加入过

    while (n--)
    {
        string command;
        cin >> command;

        if (command == "add")
        {
            int x;
            cin >> x;
            elements[x]++;
            added[x] = true;
            cout << elements[x] << endl;
        }
        else if (command == "del")
        {
            int x;
            cin >> x;
            cout << elements[x] << endl;
            elements[x] = 0;
        }
        else if (command == "ask")
        {
            int x;
            cin >> x;
            cout << added[x] << " " << elements[x] << endl;
        }
    }

    return 0;
}
