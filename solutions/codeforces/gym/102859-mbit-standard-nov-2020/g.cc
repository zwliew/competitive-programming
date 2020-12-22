#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> moves;
  vector<vector<int>> piles(M);
  for (int i = 0; i < M; ++i) {
    int R;
    cin >> R;
    piles[i].resize(R);
    for (int j = R - 1; j >= 0; --j) {
      cin >> piles[i][j];
    }
  }

  for (int i = 1; i < M; ++i) {
    for (int j = (int)piles[i].size() - 1; j >= 0; --j) {
      moves.emplace_back(i + 1, 1);
      piles[0].push_back(piles[i][j]);
    }
  }

  piles[1].clear();
  for (int i = (int)piles[0].size() - 1; i >= 0; --i) {
    int cur = piles[0][i];
    if (cur <= 2) {
      piles[1].push_back(cur);
      moves.emplace_back(1, 2);
    } else {
      moves.emplace_back(1, cur);
    }
  }

  int third = 0;
  for (int i = (int)piles[1].size() - 1; i >= 0; --i) {
    if (piles[1][i] == 1) {
      moves.emplace_back(2, 1);
    } else {
      ++third;
      moves.emplace_back(2, 3);
    }
  }

  while (third--) {
    moves.emplace_back(3, 2);
  }

  cout << moves.size() << "\n";
  for (auto& [x, y] : moves) {
    cout << x << " " << y << "\n";
  }
}
