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

  int N;
  cin >> N;
  vector<array<int, 3>> pos(N);
  vector<bool> eliminated(N);
  for (int i = 0; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    pos[i] = {x, y, i};
  }

  int cur = 0;
  for (int i = 0; i < N - 1; ++i) {
    int idx = 0;
    for (; idx < pos.size(); ++idx) {
      if (pos[idx][2] == cur)
        break;
    }

    int closestIdx = -1;
    int64_t closestDist = LLONG_MAX;
    for (int j = 0; j < pos.size(); ++j) {
      if (j == idx)
        continue;
      int64_t dx = pos[j][0] - pos[idx][0];
      int64_t dy = pos[j][1] - pos[idx][1];
      int64_t d = dx * dx + dy * dy;
      if (closestDist > d) {
        closestDist = d;
        closestIdx = j;
      }
    }

    eliminated[pos[closestIdx][2]] = true;
    pos.erase(pos.begin() + closestIdx);

    do {
      cur = (cur + 1) % N;
    } while (eliminated[cur]);
  }

  cout << cur + 1;
}
