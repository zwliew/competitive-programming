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

  int n, l;
  cin >> n >> l;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());

  ld ans = max(a[0], l - a.back());
  for (int i = 1; i < n; ++i) {
    ans = max(ans, (a[i] - a[i - 1]) / (ld)2);
  }
  cout << fixed << setprecision(9) << ans;
}