/*
算法：位运算
难度：★★★☆☆ (3星)
描述：找到下一个具有相同二进制1个数的数
算法分析：
1. 使用位运算计算二进制中1的个数
2. 关键步骤：
   - 找到最右边的01模式
   - 将其变为10
   - 将右边的1移到最右侧
3. 时间复杂度：O(logN)
*/

#include <iostream>

using namespace std;

// Function to count the number of '1's in the binary representation of n
int countOnes(int n) {
    int count = 0;
    while (n) {
        count += (n & 1); // Increment count if the last bit is 1
        n >>= 1;          // Right shift n to check the next bit
    }
    return count;
}

// Function to find the next integer with the same number of '1's
int findNextWithSameOnes(int n) {
    int c = n;
    int c0 = 0; // Count of trailing zeros
    int c1 = 0; // Count of ones

    // Count trailing zeros and ones
    while ((c & 1) == 0 && c != 0) {
        c0++;
        c >>= 1;
    }
    while ((c & 1) == 1) {
        c1++;
        c >>= 1;
    }

    // If n is of the form 111...11000...0, there is no bigger number with the same number of 1's
    if (c0 + c1 == 31 || c0 + c1 == 0) {
        return -1; // Indicating no larger number with the same number of 1's
    }

    // Position of rightmost non-trailing zero
    int p = c0 + c1; // Position of rightmost non-trailing zero

    // Flip the rightmost non-trailing zero
    n |= (1 << p); // Flip the rightmost non-trailing zero

    // Clear all bits to the right of p
    n &= ~((1 << p) - 1);

    // Insert (c1-1) ones on the right.
    n |= (1 << (c1 - 1)) - 1;

    return n;
}

int main() {
    int I;
    while (true) {
        cin >> I;
        if (I == 0) {
            break; // Terminate on input 0
        }

        int J = findNextWithSameOnes(I);
        cout << J << endl;
    }

    return 0;
}
