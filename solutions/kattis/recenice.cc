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

vector<string> small = {"",        "one",       "two",      "three",
                        "four",    "five",      "six",      "seven",
                        "eight",   "nine",      "ten",      "eleven",
                        "twelve",  "thirteen",  "fourteen", "fifteen",
                        "sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> tens = {"",      "",      "twenty",  "thirty", "forty",
                       "fifty", "sixty", "seventy", "eighty", "ninety"};

string getVal(int x) {
  if (x < 20) {
    return small[x];
  }
  if (x < 100) {
    return tens[x / 10] + getVal(x % 10);
  }
  return small[x / 100] + "hundred" + getVal(x % 100);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n;
  cin >> n;
  string s;
  vector<string> words;
  int idx = 0;
  int totalSize = 0;
  while (cin >> s) {
    if (s != "$") {
      totalSize += s.size();
      words.push_back(s);
    } else {
      idx = words.size();
      words.push_back("");
    }
  }

  for (int i = 1; i <= 999; ++i) {
    string cur = getVal(i);
    if (cur.size() + totalSize == i) {
      words[idx] = cur;
      break;
    }
  }
  for (auto x : words) {
    cout << x << " ";
  }
}
