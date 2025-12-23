#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K, P;
    cin >> N >> K >> P;
    int M = K / N; // Bessie 要拿 M 张好牌

    queue<int> q;
    for (int i = 1; i <= K; ++i) q.push(i);

    vector<int> bessie_cards;
    int turn = 0; // 0: P1, 1: P2, ..., N-1: Bessie

    while (!q.empty()) {
        int card = q.front(); q.pop();
        if (turn == N-1) {
            bessie_cards.push_back(card);
            if (bessie_cards.size() == M) break;
        }
        // P 张牌放到底部
        for (int i = 0; i < P && !q.empty(); ++i) {
            q.push(q.front());
            q.pop();
        }
        turn = (turn + 1) % N;
    }

    sort(bessie_cards.begin(), bessie_cards.end());
    for (int c : bessie_cards) cout << c << endl;
}