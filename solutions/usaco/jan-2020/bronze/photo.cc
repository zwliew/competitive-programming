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

  freopen("photo.in", "r", stdin);
  freopen("photo.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> b(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> b[i];
  }

  vector<int> a(n);
  bitset<10001> seen;
  for (int i = 1; i <= n; ++i) {
    seen.reset();
    a[0] = i;
    seen.set(a[0]);
    bool f = 1;
    for (int j = 1; j < n; ++j) {
      a[j] = b[j - 1] - a[j - 1];
      if (a[j] > n || a[j] <= 0 || seen.test(a[j])) {
        f = 0;
        break;
      }
      seen.set(a[j]);
    }
    if (f) {
      for (int j = 0; j < n - 1; ++j) {
        cout << a[j] << ' ';
      }
      cout << a[n - 1];
      break;
    }
  }
}