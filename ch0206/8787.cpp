#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> a(n + 1, vector<int>(k + 1, 0));

    // 初始化
    for (int i = 1; i <= n; ++i) {
        a[i][1] = 1;
    }

    // 填充dp表
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= k; ++j) {
            if (i > j) {
                a[i][j] = a[i - 1][j - 1] + a[i - j][j];
            } else {
                a[i][j] = a[i - 1][j - 1];
            }
        }
    }

    cout << a[n][k] << endl;

    return 0;
}