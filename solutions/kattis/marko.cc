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

  vector<int> positions = {
      2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6,
      6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9,
  };

  int n;
  cin >> n;
  vector<string> dictionary;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (auto& c : s) {
      c = positions[c - 'a'] + '0';
    }
    dictionary.push_back(s);
  }
  string s;
  cin >> s;
  int count = 0;
  for (auto& x : dictionary) {
    if (s == x) {
      ++count;
    }
  }
  cout << count;
}
