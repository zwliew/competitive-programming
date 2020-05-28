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
typedef long double ld;

int dp(vector<vector<int>> &mem, vector<vector<int>> &prefixes, int p,
       int idx) {
  if (idx < 0) return 0;
  if (!p) return 0;
  if (p < 0) return -1e8;
  if (mem[p][idx] != -1) return mem[p][idx];
  int cur = 0;
  for (int i = 0; i <= min<int>(p, prefixes[idx].size() - 1); ++i) {
    cur = max(cur, dp(mem, prefixes, p - i, idx - 1) + prefixes[idx][i]);
  }
  return mem[p][idx] = cur;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    int n, k, p;
    cin >> n >> k >> p;

    vector<vector<int>> mem(1501, vector<int>(51, -1));

    vector<vector<int>> prefixes(n, vector<int>(k + 1, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < k; ++j) {
        int x;
        cin >> x;
        prefixes[i][j + 1] = prefixes[i][j] + x;
      }
    }

    cout << "Case #" << ti << ": " << dp(mem, prefixes, p, n - 1) << '\n';
  }
}