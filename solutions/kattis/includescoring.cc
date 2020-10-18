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
#include <map>
#include <numeric>
#include <queue>
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

struct Props {
  int solved, time, last;
  int idx;
  Props(int a, int b, int c, int d) : solved(a), time(b), last(c), idx(d) {}
  bool operator<(const auto& x) const {
    if (solved != x.solved) {
      return solved > x.solved;
    }
    if (time != x.time) {
      return time < x.time;
    }
    return last < x.last;
  }
  bool operator==(const auto& x) const {
    return tie(solved, time, last) == tie(x.solved, x.time, x.last);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<Props> contestants;
  vector<int> scores(n);
  for (int i = 0; i < n; ++i) {
    int s, p, f, o;
    cin >> s >> p >> f >> o;
    contestants.emplace_back(s, p, f, i);
    scores[i] += o;
  }
  sort(contestants.begin(), contestants.end());

  vector<int> rankToScore = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26,
                             24,  22, 20, 18, 16, 15, 14, 13, 12, 11,
                             10,  9,  8,  7,  6,  5,  4,  3,  2,  1};
  for (int i = 0; i < n;) {
    int last = i;
    int totalScore = 0;
    while (last < n && contestants[last] == contestants[i]) {
      totalScore += last < rankToScore.size() ? rankToScore[last] : 0;
      ++last;
    }
    totalScore = (totalScore + last - i - 1) / (last - i);
    for (int j = i; j < last; ++j) {
      scores[contestants[j].idx] += totalScore;
    }
    i = last;
  }

  for (int i = 0; i < n; ++i) {
    cout << scores[i] << "\n";
  }
}
