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

  // Build an adjacency list and check if there are 0 other neighbours for a
  // candidate word
  string src;
  cin >> src;
  int n;
  cin >> n;
  unordered_map<char, vector<string>> ht;
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    ht[x.front()].emplace_back(x);
  }

  string pos = "";
  for (string candidate : ht[src.back()]) {
    if (ht[candidate.back()].empty() ||
        (ht[candidate.back()].size() == 1 &&
         ht[candidate.back()].front() == candidate)) {
      cout << candidate << '!';
      return 0;
    }
    if (pos.empty()) pos = candidate;
  }

  if (pos.empty()) {
    cout << "?";
  } else {
    cout << pos;
  }
}
