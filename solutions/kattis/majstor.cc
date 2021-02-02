#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  unordered_map<char, int> mp = {{'R', 0}, {'S', 1}, {'P', 2}};
  int R;
  cin >> R;
  vector<int> actual(R);
  for (auto& x : actual) {
    char c;
    cin >> c;
    x = mp[c];
  }

  int score = 0;
  vector<vector<int>> rounds(R, vector<int>(3));
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < R; ++j) {
      char c;
      cin >> c;
      int x = mp[c];
      rounds[j][x]++;
      if (actual[j] == x) {
        ++score;
      } else if (actual[j] == (x + 2) % 3) {
        score += 2;
      }
    }
  }

  cout << score << "\n";

  score = 0;
  for (int i = 0; i < R; ++i) {
    int best = 0;
    for (int j = 0; j < 3; ++j) {
      best = max(best, rounds[i][(j + 1) % 3] * 2 + rounds[i][j]);
    }
    score += best;
  }
  cout << score;
}
