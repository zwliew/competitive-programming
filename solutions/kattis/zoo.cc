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

  auto strlower = [](string& s) {
    for (char& c : s) {
      if (isalpha(c)) {
        c = tolower(c);
      }
    }
  };

  int n;
  int i = 0;
  while (cin >> n && n) {
    ++i;
    map<string, int> cnt;
    string s;
    getline(cin, s);
    while (n--) {
      getline(cin, s);
      istringstream ss(s);
      while (ss >> s)
        ;
      strlower(s);
      cnt[s]++;
    }
    cout << "List " << i << ":\n";
    for (auto& [k, v] : cnt) {
      cout << k << " | " << v << '\n';
    }
  }
}
