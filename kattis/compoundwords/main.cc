#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  vector<string> words;
  string s;
  while (cin >> s) {
    words.emplace_back(s);
  }

  unordered_set<string> seen;
  vector<string> output;
  for (string x : words) {
    for (string y : words) {
      if (x == y) continue;
      string next = x + y;
      if (!seen.count(next)) {
        seen.emplace(next);
        output.emplace_back(next);
      }
    }
  }

  sort(output.begin(), output.end());
  for (string x : output) {
    cout << x << '\n';
  }
}
