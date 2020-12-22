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
#include <random>
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

  vector<string> required = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
  auto isnum = [](string x, int l, int r) {
    for (char c : x) {
      if (!isdigit(c)) {
        return false;
      }
    }
    int xi = stoi(x);
    return xi >= l && xi <= r;
  };
  
  int cnt = 0;
  string s;
  while (getline(cin, s)) {
    string cur = s;
    while (getline(cin, s) && s != "") {
      cur += " ";
      cur += s;
    }

    vector<bool> found(required.size());
    istringstream ss(cur);
    while (ss >> s) {
      string k = s.substr(0, 3);
      string v = s.substr(4);
      int idx = find(required.begin(), required.end(), k) - required.begin();
      if (idx < required.size()) {
        if (k == "byr") {
          found[idx] = v.size() == 4 && isnum(v, 1920, 2002);
        } else if (k == "iyr") {
          found[idx] = v.size() == 4 && isnum(v, 2010, 2020);
        } else if (k == "eyr") {
          found[idx] = v.size() == 4 && isnum(v, 2020, 2030);
        } else if (k == "hgt" && v.size() > 2) {
          string suf = v.substr(v.size() - 2);
          string pre = v.substr(0, v.size() - 2);
          if (suf == "cm" && isnum(pre, 150, 193)) {
            found[idx] = true;
          } else if (suf == "in" && isnum(pre, 59, 76)) {
            found[idx] = true;
          }
        } else if (k == "hcl") {
          found[idx] = v[0] == '#' && v.size() == 7;
          for (int i = 1; i < v.size(); ++i) {
            if (!isdigit(v[i]) && v[i] < 'a' && v[i] > 'f') {
              found[idx] = false;
              break;
            }
          }
        } else if (k == "ecl") {
          const vector<string> allowed = {"amb", "blu", "brn", "gry",
                                          "grn", "hzl", "oth"};
          found[idx] = find(allowed.begin(), allowed.end(), v) != allowed.end();
        } else if (k == "pid") {
          found[idx] = v.size() == 9;
          for (char c : v) {
            if (!isdigit(c)) {
              found[idx] = false;
              break;
            }
          }
        }
      }
    }

    if (accumulate(found.begin(), found.end(), 0) == found.size()) {
      ++cnt;
    }
  }
  cout << cnt;
}
