#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int MAX=50000;
    int n;
    cin>>n;
    if (n == 0)
    {
        cout<<("1")<<endl;
        return 0;
    }

    int arr[MAX] = {0};
    arr[0] = 1;
    int carry = 0;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            arr[j] = arr[j] * i + carry;
            carry = arr[j] / 10; // 要进位的数
            arr[j] = arr[j] % 10;
        }
    }
    int size = MAX-1;
    while (arr[size] == 0)
    {
        size--;
    }
    for (int i = size; i >= 0; i--)
    {
        cout<<arr[i];
    }
    cout<<endl;
    return 0;
}