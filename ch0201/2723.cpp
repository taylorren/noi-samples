#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 获取一个数的所有因子
vector<int> getFactors(int n) {
  vector<int> factors;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      factors.push_back(i);
    }
  }
  return factors;
}

// 二分查找函数
bool binary_search(const vector<int> &arr, int target) {
  int left = 0, right = arr.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
      return true;
    if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return false;
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> factors = getFactors(N);
  int result = -1;

  // 遍历所有因子
  for (int a : factors) {
    int b = M - a;
    // 只需要检查b是否在factors中
    if (binary_search(factors, b)) {
      result = a;
      break;
    }
  }

  cout << result << endl;
  return 0;
}
