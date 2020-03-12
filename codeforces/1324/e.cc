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

int n, h, l, r;
vector<int> a;

vector<vector<int>> mem(2005, vector<int>(2005, -1));

int dp(int idx, int t) {
  if (idx == n) {
    return 0;
  }

  if (mem[idx][t] != -1) {
    return mem[idx][t];
  }

  int c = (t + a[idx]) % h;
  int cmax = dp(idx + 1, c) + (c >= l && c <= r);
  c = (t + a[idx] - 1) % h;
  cmax = max(cmax, dp(idx + 1, c) + (c >= l && c <= r));
  return mem[idx][t] = cmax;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> h >> l >> r;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a.push_back(x);
  }

  cout << dp(0, 0);
}