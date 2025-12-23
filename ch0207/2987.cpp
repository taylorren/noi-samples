#include <iostream>
using namespace std;

// 计算螺旋矩阵中(i,j)位置的值
long long getValueAt(int i, int j, int n) {
    // 将坐标转换为0-indexed
    i--;
    j--;
    
    // 计算(i,j)所在的层数
    int layer = min(min(i, j), min(n-1-i, n-1-j));
    
    // 计算当前层的起始值
    long long start = 4 * layer * (n - layer);
    
    // 计算当前层的边长
    int side_len = n - 2 * layer;
    
    // 判断(i,j)在当前层的哪一条边上
    if (i == layer) {
        // 上边
        return start + 1 + (j - layer);
    } else if (j == n - 1 - layer) {
        // 右边
        return start + 1 + (side_len - 1) + (i - layer);
    } else if (i == n - 1 - layer) {
        // 下边
        return start + 1 + 2 * (side_len - 1) + (n - 1 - layer - j);
    } else {
        // 左边
        return start + 1 + 3 * (side_len - 1) + (n - 1 - layer - i);
    }
}

int main() {
    int k, n;
    cin >> k >> n;
    
    for (int t = 0; t < k; t++) {
        int i, j;
        cin >> i >> j;
        cout << getValueAt(i, j, n) << endl;
    }
    
    return 0;
}