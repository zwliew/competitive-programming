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

  int n, k;
  cin >> n >> k;
  vector<queue<string>> prefs(n);
  for (int i = 0; i < n; ++i) {
    int q;
    cin >> q;
    while (q--) {
      string x;
      cin >> x;
      prefs[i].push(x);
    }
  }

  int p;
  cin >> p;
  unordered_set<string> undrafted;
  queue<string> rankings;
  for (int i = 0; i < p; ++i) {
    string s;
    cin >> s;
    undrafted.insert(s);
    rankings.push(s);
  }

  vector<vector<string>> drafts(n, vector<string>(k));
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      while (prefs[j].size() && !undrafted.count(prefs[j].front())) {
        prefs[j].pop();
      }
      if (prefs[j].empty()) {
        while (rankings.size() && !undrafted.count(rankings.front())) {
          rankings.pop();
        }
        drafts[j][i] = rankings.front();
        undrafted.erase(rankings.front());
        rankings.pop();
      } else {
        undrafted.erase(prefs[j].front());
        drafts[j][i] = prefs[j].front();
        prefs[j].pop();
      }
    }
  }

  for (auto& v : drafts) {
    for (auto& s : v) {
      cout << s << " ";
    }
    cout << "\n";
  }
}
