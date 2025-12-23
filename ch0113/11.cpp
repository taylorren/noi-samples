#include <bits/stdc++.h>
using namespace std;

// 优化的素数判断函数
bool is_prime(long long n) {
  if (n < 2)
    return false;
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;
  for (long long i = 3; i * i <= n; i += 2) {
    if (n % i == 0)
      return false;
  }
  return true;
}

// 生成回文数函数 - 只处理奇数长度的情况
long long make_palindrome(int x) {
  long long result = x;
  int temp = x / 10; // 去掉中间数字
  while (temp > 0) {
    result = result * 10 + temp % 10;
    temp /= 10;
  }
  return result;
}

int main() {
  int l;
  cin >> l;

  // 特殊情况处理
  if (l == 1) {
    cout << 4 << endl << "2 3 5 7" << endl;
    return 0;
  }
  if (l == 2) {
    cout << 1 << endl << "11" << endl;
    return 0;
  }
  // 偶数位数的回文数必然不是素数（都是11的倍数）
  if (l % 2 == 0) {
    cout << 0 << endl;
    return 0;
  }

  // 计算范围 - 只需处理奇数长度的情况
  int half_l = (l + 1) / 2;
  int min_val = pow(10, half_l - 1);
  int max_val = pow(10, half_l) - 1;

  vector<long long> res;
  for (int i = min_val; i <= max_val; i++) {
    long long palindrome = make_palindrome(i);
    if (is_prime(palindrome)) {
      res.push_back(palindrome);
    }
  }

  // 输出结果
  cout << res.size() << endl;
  for (long long num : res) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}