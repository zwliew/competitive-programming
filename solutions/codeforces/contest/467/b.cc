#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
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

typedef long long ll;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> x(m + 1);
  for (int i = 0; i < m + 1; ++i) {
    cin >> x[i];
  }

  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    if (__builtin_popcount(x[m] ^ x[i]) <= k) ++cnt;
  }
  cout << cnt;
}