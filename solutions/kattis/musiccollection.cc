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

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    cout << "Case #" << ti << ":\n";

    unordered_map<string, int> cnt;
    int n;
    cin >> n;
    vector<string> names;
    {
      string name;
      getline(cin, name);
      for (int i = 0; i < n; ++i) {
        getline(cin, name);
        for (char& c : name) {
          if (isalpha(c)) {
            c = toupper(c);
          }
        }
        names.push_back(name);
        unordered_set<string> seen;
        for (int l = 0; l < name.size(); ++l) {
          string cur;
          for (int r = l; r < name.size(); ++r) {
            cur += name[r];
            if (!seen.count(cur)) {
              cnt[cur]++;
              seen.insert(cur);
            }
          }
        }
      }
    }

    if (n == 1) {
      cout << "\"\"\n";
    } else {
      for (auto& name : names) {
        string best;
        for (int l = 0; l < name.size(); ++l) {
          string cur;
          for (int r = l; r < name.size(); ++r) {
            cur += name[r];
            if (cnt[cur] == 1 && (best.empty() || cur.size() < best.size() ||
                                  (cur.size() == best.size() && cur < best))) {
              best = cur;
            }
          }
        }
        if (best.empty()) {
          cout << ":(\n";
        } else {
          cout << "\"" << best << "\"\n";
        }
      }
    }
  }
}
