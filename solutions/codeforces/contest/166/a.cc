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

  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> v(n);
  for (auto &x : v) {
    cin >> x.first >> x.second;
  }
  --k;
  nth_element(v.begin(), v.begin() + k, v.end(),
              [](const auto &x, const auto &y) {
                if (x.first != y.first) return x.first > y.first;
                return x.second < y.second;
              });
  int c = 0;
  // cout << v[k].first << ' ' << v[k].second << '\n';
  for (auto &[x, y] : v) {
    if (x == v[k].first && y == v[k].second) {
      ++c;
    }
  }
  cout << c;
}
