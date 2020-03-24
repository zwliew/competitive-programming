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

  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    int n, b;
    cin >> n >> b;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    int j = 0;
    while (j < n && b >= a[j]) {
      b -= a[j++];
      ++cnt;
    }
    cout << "Case #" << i << ": " << cnt << '\n';
  }
}