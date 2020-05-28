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

  int k, n;
  cin >> k >> n;
  vector<int> a(n);
  int maxd = 0, maxidx = -1;
  for (auto &x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());
  for (int i = 1; i < n; ++i) {
    if (a[i] - a[i - 1] > maxd) {
      maxd = a[i] - a[i - 1];
      maxidx = i;
    }
  }
  int first = a.back() - a.front();
  first = min(first, k - a[maxidx] + a[maxidx - 1]);
  cout << first;
}
