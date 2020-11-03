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

  string S;
  while (cin >> S && S != "0") {
    int N = stoi(S.substr(0, S.size() - 1));
    vector<int> pos(N);
    for (int i = 0; i < N; ++i) {
      int x;
      cin >> x;
      pos[x] = i;
    }

    bool found = false;
    for (int f = 0; f < N; ++f) {
      for (int d = -N + 1; d < N; ++d) {
        int s = f + d;
        int t = s + d;
        if (t >= 0 && t < N && pos[f] < pos[s] && pos[s] < pos[t]) {
          found = true;
          break;
        }
      }
      if (found) {
        break;
      }
    }

    if (found) {
      cout << "no";
    } else {
      cout << "yes";
    }
    cout << "\n";
  }
  vector<int> pos()
}
