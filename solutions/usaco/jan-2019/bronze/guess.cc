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
#define FILE "guess"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int N;
  cin >> N;
  vector<unordered_set<string>> animals(N);
  for (int i = 0; i < N; ++i) {
    string s;
    int K;
    cin >> s >> K;
    for (int j = 0; j < K; ++j) {
      string c;
      cin >> c;
      animals[i].insert(c);
    }
  }

  int best = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      int cur = 1;
      for (auto& c : animals[i]) {
        if (animals[j].count(c)) {
          ++cur;
        }
      }
      best = max(best, cur);
    }
  }
  cout << best;
}
