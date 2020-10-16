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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  vector<string> names(n);
  for (auto& x : names) {
    cin >> x;
  }

  vector<string> words = {
      "Happy", "birthday", "to", "you",   "Happy", "birthday", "to", "you",
      "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you",
  };

  int times = (names.size() + words.size() - 1) / words.size();
  int endIdx = times * words.size();
  for (int i = 0; i < endIdx; ++i) {
    cout << names[i % names.size()] << ": " << words[i % words.size()] << "\n";
  }
}
