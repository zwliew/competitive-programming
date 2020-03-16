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

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<bool> seen(100000 + 1, 0);
  seen[a[n - 1]] = 1;
  a[n - 1] = 1;

  for (int i = n - 2; i >= 0; --i) {
    int tmp = a[i];
    a[i] = a[i + 1] + !seen[a[i]];
    seen[tmp] = 1;
  }

  for (int i = 0; i < m; ++i) {
    int l;
    cin >> l;
    cout << a[l - 1] << '\n';
  }
}