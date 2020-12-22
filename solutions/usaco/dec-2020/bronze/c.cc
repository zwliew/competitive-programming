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
  array<vector<array<int, 3>>, 2> pos;
  for (int i = 0; i < N; ++i) {
    char c;
    int x, y;
    cin >> c >> x >> y;
    int idx = c == 'N';
    pos[idx].push_back({x, y, i});
  }

  vector<array<int, 2>> epos(N, {-1, -1});
  vector<int> ans(N, -1);

  while (true) {
    int bestDist = INT_MAX;
    array<int, 3> bestPos;

    for (int i = 0; i < pos[0].size(); ++i) {
      int ix = pos[0][i][0];
      int iy = pos[0][i][1];
      int ii = pos[0][i][2];
      for (int j = 0; j < pos[1].size(); ++j) {
        int jx = pos[1][j][0];
        int jy = pos[1][j][1];
        int ji = pos[1][j][2];

        if (jx < ix || jy > iy)
          continue;

        if (epos[ii][0] == -1 && iy - jy < jx - ix &&
            (epos[ji][0] == -1 || epos[ji][1] > iy) && bestDist > jx - ix) {
          bestDist = jx - ix;
          bestPos = pos[0][i];
        }

        if (epos[ji][0] == -1 && jx - ix < iy - jy &&
            (epos[ii][0] == -1 || epos[ii][0] > jx) && bestDist > iy - jy) {
          bestDist = iy - jy;
          bestPos = pos[1][j];
        }
      }
    }

    if (bestDist == INT_MAX) {
      break;
    }

    int idx = 0;
    for (int i = 0; i < pos[1].size(); ++i) {
      if (pos[1][i][0] == bestPos[0]) {
        idx = 1;
        break;
      }
    }

    ans[bestPos[2]] = bestDist;
    epos[bestPos[2]] = {bestPos[0], bestPos[1]};
    epos[bestPos[2]][idx] += bestDist;
  }

  for (int x : ans) {
    if (x == -1) {
      cout << "Infinity";
    } else {
      cout << x;
    }
    cout << "\n";
  }
}
