#include<bits/stdc++.h>
using namespace std;
 
// Function to find number of consecutive Zero Pairs
// Here n is number of steps
int consecutiveZeroPairs(int n)
{
    // Base cases
    if (n==1)
        return 0;
    if (n==2 || n==3)
        return 1;
 
    // Calculating how many times divisible by 12, i.e.,
    // count total number repeating segments of length 12
    int q = ((1LL << n) / 12);
 
    // number of consecutive Zero Pairs
    return 2 * q + 1;
}
 
// Driver code
int main()
{
    int n;
    while(cin >> n) {
        cout << consecutiveZeroPairs(n) << endl;
    }
}

//https://www.geeksforgeeks.org/count-pairs-of-consecutive-zeros/
//这道题的核心，是12次操作后就开始循环

//n=4: 16位：从12位开始重复。1001 0110 0110 1001
//前12位有两对，2^n/12*2应该是可以算出来的