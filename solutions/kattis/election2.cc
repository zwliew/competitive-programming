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

  int n;
  cin >> n;
  unordered_map<string, string> parties;
  unordered_map<string, int> freqs;
  string s;
  getline(cin, s);
  while (n--) {
    getline(cin, s);
    string x;
    getline(cin, x);
    parties[s] = x;
  }
  cin >> n;
  getline(cin, s);
  while (n--) {
    getline(cin, s);
    freqs[s]++;
  }

  string winner;
  int maxFreq = 0;
  int cnt = 0;
  for (auto& [k, v] : freqs) {
    if (v > maxFreq) {
      winner = k;
      maxFreq = v;
      cnt = 1;
    } else if (v == maxFreq) {
      ++cnt;
    }
  }

  if (cnt > 1) {
    cout << "tie";
  } else {
    cout << parties[winner];
  }
}
