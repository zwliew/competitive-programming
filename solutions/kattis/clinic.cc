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

struct cmp {
  bool operator()(const pair<int64_t, string>& x,
                  const pair<int64_t, string>& y) const {
    if (x.first == y.first)
      return x.second < y.second;
    return x.first > y.first;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  // Use a set to keep track of the highest priority patient
  int n, k;
  cin >> n >> k;
  set<pair<int64_t, string>, cmp> patients;
  unordered_map<string, int64_t> mp;
  while (n--) {
    int q;
    cin >> q;
    if (q == 1) {
      int t, s;
      string m;
      cin >> t >> m >> s;
      // s1 + k*(t-t1) >= s2 + k * (t - t2)
      // s1 - k * t1 >= s2 - k * t2
      patients.emplace(s - (int64_t)k * t, m);
      mp[m] = s - (int64_t)k * t;
    } else if (q == 2) {
      int t;
      cin >> t;
      if (patients.empty()) {
        cout << "doctor takes a break\n";
      } else {
        cout << patients.begin()->second << '\n';
        mp.erase(patients.begin()->second);
        patients.erase(patients.begin());
      }
    } else {
      int t;
      string m;
      cin >> t >> m;
      auto it = mp.find(m);
      if (it != mp.end()) {
        patients.erase(make_pair(it->second, it->first));
        mp.erase(it);
      }
    }
  }
}
