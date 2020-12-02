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

  string line;
  int cnt = 0;
  while (getline(cin, line)) {
    array<int, 26> freq;
    fill(freq.begin(), freq.end(), 0);
    int i = line.find("-");
    int j = line.find(" ");
    int l = stoi(line.substr(0, i));
    int r = stoi(line.substr(i + 1, j - i - 1));
    char c = line[j + 1];
    string s = line.substr(j + 4);
    int cur = (s[l - 1] == c) + (s[r - 1] == c);
    if (cur == 1)
      ++cnt;
  }
  cout << cnt;
}
