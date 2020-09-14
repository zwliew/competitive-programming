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
//#include "bits/stdc++.h"

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

  // Use a hashmap to efficiently map foreign words to english words
  unordered_map<string, string> m;
  string s;
  while (getline(cin, s) && !s.empty()) {
    stringstream ss(s);
    vector<string> v;
    while (ss >> s) {
      v.push_back(s);
    }
    m[v[1]] = v[0];
  }

  while (cin >> s) {
    if (m.count(s)) {
      cout << m[s] << '\n';
    } else {
      cout << "eh\n";
    }
  }
}
