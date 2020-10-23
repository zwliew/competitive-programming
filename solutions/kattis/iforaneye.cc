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

  unordered_map<string, char> subs = {
      {"at", '@'},  {"and", '&'}, {"one", '1'}, {"won", '1'},  {"to", '2'},
      {"too", '2'}, {"two", '2'}, {"for", '4'}, {"four", '4'}, {"be", 'b'},
      {"bee", 'b'}, {"bea", 'b'}, {"see", 'c'}, {"sea", 'c'},  {"eye", 'i'},
      {"oh", 'o'},  {"owe", 'o'}, {"are", 'r'}, {"you", 'u'},  {"why", 'y'},
  };

  auto extract = [](string& s, int i, int l) {
    string res = s.substr(i, l);
    for (char& c : res) {
      c = tolower(c);
    }
    return res;
  };

  auto match = [](char orig, int nxt) {
    if (isupper(orig)) {
      return toupper(nxt);
    }
    return nxt;
  };

  int n;
  cin >> n;
  string line;
  getline(cin, line);
  while (n--) {
    getline(cin, line);
    istringstream ss(line);
    string s;
    while (ss >> s) {
      string rep;
      for (int i = 0; i < s.size(); ++i) {
        bool found = false;
        if (i + 3 < s.size()) {
          string cur = extract(s, i, 4);
          if (subs.count(cur)) {
            rep += match(s[i], subs[cur]);
            i += 3;
            found = true;
          }
        }

        if (!found && i + 2 < s.size()) {
          string cur = extract(s, i, 3);
          if (subs.count(cur)) {
            rep += match(s[i], subs[cur]);
            i += 2;
            found = true;
          }
        }

        if (!found && i + 1 < s.size()) {
          string cur = extract(s, i, 2);
          if (subs.count(cur)) {
            rep += match(s[i], subs[cur]);
            ++i;
            found = true;
          }
        }

        if (!found) {
          rep += s[i];
        }
      }
      cout << rep << " ";
    }
    cout << "\n";
  }
}
