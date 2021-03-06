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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = 1; i < n; ++i) {
    int tmp = max(0, k - a[i] - a[i - 1]);
    a[i] += tmp;
    cnt += tmp;
  }
  cout << cnt << '\n';
  for (int i = 0; i < n; ++i) {
    cout << a[i] << ' ';
  }
}