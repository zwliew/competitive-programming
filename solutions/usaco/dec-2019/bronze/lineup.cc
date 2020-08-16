/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE "lineup"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  unordered_map<string, vector<string>> adj;
  string s;
  getline(cin, s);
  while (n--) {
    getline(cin, s);
    stringstream ss(s);
    string first, last;
    bool f = true;
    while (ss >> s) {
      if (f) {
        f = false;
        first = s;
      }
      last = s;
    }
    adj[last].emplace_back(first);
    adj[first].emplace_back(last);
  }

  vector<string> cows = {
      "Bessie", "Buttercup", "Belinda", "Beatrice",
      "Bella",  "Blue",      "Betsy",   "Sue",
  };
  sort(cows.begin(), cows.end());

  do {
    bool ok = true;
    for (int i = 0; i < 8 && ok; ++i) {
      for (string& neighbour : adj[cows[i]]) {
        if ((!i || cows[i - 1] != neighbour) &&
            (i == 7 || cows[i + 1] != neighbour)) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      for (string cow : cows) {
        cout << cow << '\n';
      }
      return 0;
    }
  } while (next_permutation(cows.begin(), cows.end()));
}
