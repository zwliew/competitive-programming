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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, x, y;
  cin >> n >> x >> y;

  vector<int> k(n, 0);
  vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      adj[i][j] = min({adj[i][j - 1] + 1, abs(x - i) + abs(j - y) + 1});
      k[adj[i][j]]++;
    }
  }

  for (int i = 1; i <= n - 1; ++i) {
    cout << k[i] << '\n';
  }
}
