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
  unordered_set<string> unique;
  string s;
  getline(cin, s);
  while (n--) {
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i) {
      if (isalpha(s[i])) {
        s[i] = tolower(s[i]);
      } else if (s[i] == '-') {
        s[i] = ' ';
      }
    }
    unique.insert(s);
  }
  cout << unique.size();
}
