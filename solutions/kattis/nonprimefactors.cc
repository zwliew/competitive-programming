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

const int MAXN = 2'000'000;
array<int, MAXN + 1> numPf, numDiv;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  fill(numDiv.begin(), numDiv.end(), 1);
  fill(numPf.begin(), numPf.end(), 0);

  for (int i = 2; i <= MAXN; ++i) {
    if (!numPf[i]) {
      for (int j = i; j <= MAXN; j += i) {
        numPf[j]++;

        int tmp = j;
        int cnt = 0;
        while (tmp % i == 0) {
          tmp /= i;
          ++cnt;
        }
        numDiv[j] *= cnt + 1;
      }
    }
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int x;
    cin >> x;
    cout << numDiv[x] - numPf[x] << "\n";
  }
}
