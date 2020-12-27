#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  string S;
  int E, P;
  cin >> S >> E;
  vector<unordered_set<string>> endings(E);
  string line;
  getline(cin, line);
  for (auto& s : endings) {
    getline(cin, line);
    stringstream ss(line);
    while (ss >> line) {
      s.insert(line);
    }
  }
  cin >> P;
  getline(cin, line);
  while (P--) {
    getline(cin, line);
    bool ok = false;
    for (auto& s : endings) {
      bool af = false, bf = false;
      for (auto& x : s) {
        if (!af && S.size() >= x.size() && S.substr(S.size() - x.size()) == x) {
          af = true;
        }
        if (!bf && line.size() >= x.size() &&
            line.substr(line.size() - x.size()) == x) {
          bf = true;
        }
      }
      if (af && bf) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << "\n";
  }
}
