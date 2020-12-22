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

  int N;
  cin >> N;
  while (N--) {
    int K;
    cin >> K;
    cout << K << " ";
    string s;
    cin >> s;
    int idx = s.find('/');
    int p = stoi(s.substr(0, idx));
    int q = stoi(s.substr(idx + 1));

    if (q == 1) {
      cout << "1/" << p + 1 << "\n";
      continue;
    }

    int cnt = max(0, (p - 1) / q);
    p -= cnt * q;
    q -= p;
    p += q;
    q += p * cnt;
    cout << p << "/" << q << "\n";
  }
}
