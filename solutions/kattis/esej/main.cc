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

  int a, b;
  cin >> a >> b;
  vector<string> words;
  string cur = "a";
  for (int i = 0; i < ceil(b / 2.); ++i) {
    words.emplace_back(cur);
    int idx = cur.size() - 1;
    cur[idx]++;
    while (idx >= 0 && cur[idx] > 'z') {
      cur[idx] = 'a';
      --idx;
      if (idx >= 0) {
        cur[idx]++;
      } else {
        cur += 'a';
      }
    }
  }

  int cnt = 0;
  for (string x : words) {
    cout << x << ' ';
    cnt++;
  }
  for (; cnt < a; ++cnt) {
    cout << words[0] << ' ';
  }
}
