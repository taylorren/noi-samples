#include <bits/stdc++.h>
using namespace std;

int main() {
  int m;
  cin >> m;

  // 使用vector统计每个作者的书籍数量
  vector<int> books(26);   // 自动初始化为0
  vector<int> authors[26]; // 存储每个作者的书籍编号

  int book;
  string authors_list;
  char max_author = 'A'; // 写书最多的作者
  int max_books = 0;     // 最大书籍数量

  for (int i = 1; i <= m; i++) {
    cin >> book >> authors_list;
    for (char c : authors_list) {
      int idx = c - 'A';
      books[idx]++;
      authors[idx].push_back(book);

      // 实时更新最大值
      if (books[idx] > max_books ||
          (books[idx] == max_books && c < max_author)) {
        max_books = books[idx];
        max_author = c;
      }
    }
  }

  cout << max_author << endl;
  cout << max_books << endl;

  // 输出该作者的所有书籍编号
  for (int book_id : authors[max_author - 'A']) {
    cout << book_id << endl;
  }

  return 0;
}