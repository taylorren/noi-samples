#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  // 存储每个人喜欢的书
  vector<int> favorites(N);
  for (int i = 0; i < N; i++) {
    cin >> favorites[i];
  }

  // 对每个人计算潜在朋友数量
  for (int i = 0; i < N; i++) {
    int friends = 0;
    // 和其他每个人比较
    for (int j = 0; j < N; j++) {
      if (i != j && favorites[i] == favorites[j]) {
        friends++;
      }
    }
    // 输出结果
    if (friends == 0) {
      cout << "BeiJu" << endl;
    } else {
      cout << friends << endl;
    }
  }

  return 0;
}