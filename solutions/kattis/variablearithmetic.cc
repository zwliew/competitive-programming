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

  auto checkalpha = [](string s) {
    for (char c : s) {
      if (c < '0' || c > '9') {
        return false;
      }
    }
    return true;
  };

  unordered_map<string, int> defs;
  string s;
  while (getline(cin, s) && s != "0") {
    istringstream ss(s);
    vector<string> tokens;
    while (ss >> s) {
      tokens.push_back(s);
    }

    if (tokens.size() == 3 && tokens[1] == "=") {
      defs[tokens[0]] = stoi(tokens[2]);
    } else {
      int val = 0;
      vector<string> unknown;
      for (int i = 0; i < tokens.size(); i += 2) {
        if (checkalpha(tokens[i])) {
          int x = stoi(tokens[i]);
          val += x;
        } else if (!defs.count(tokens[i])) {
          unknown.push_back(tokens[i]);
        } else {
          val += defs[tokens[i]];
        }
      }
      if (val)
        cout << val;
      else
        cout << unknown.front();
      for (int i = (bool)!val; i < unknown.size(); ++i) {
        cout << " + " << unknown[i];
      }
      cout << "\n";
    }
  }
}
