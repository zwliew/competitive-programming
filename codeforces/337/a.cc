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

  int n, m;
  cin >> n >> m;

  vector<int> f(m);
  for (int i = 0; i < m; ++i) {
    cin >> f[i];
  }
  sort(f.begin(), f.end());
  int mindiff = 1e9;
  for (int i = n - 1; i < m; ++i) {
    mindiff = min(mindiff, f[i] - f[i - n + 1]);
  }
  cout << mindiff;
}