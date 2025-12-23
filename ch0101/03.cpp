#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    cout << setiosflags(ios::right) << setw(8) << a << " " << setiosflags(ios::right) << setw(8) << b << " " << setiosflags(ios::right) << setw(8) << c << endl;
    return 0;
}
