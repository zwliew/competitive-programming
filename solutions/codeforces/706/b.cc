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

  int n;
  cin >> n;

  // Binary search solution: O((n + q) * log(n))
  // vector<int> x(n);
  // for (int i = 0; i < n; ++i) {
  //   cin >> x[i];
  // }

  // sort(x.begin(), x.end());

  // int q;
  // cin >> q;
  // for (int i = 0; i < q; ++i) {
  //   int m;
  //   cin >> m;

  //   auto it = upper_bound(x.begin(), x.end(), m);
  //   cout << it - x.begin();
  //   cout << '\n';
  // }

  // DP Prefix sum solution: O(n + q)
  vector<int> xprefix(1000001, 0);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    xprefix[x]++;
  }

  for (int i = 2; i <= 100000; ++i) {
    xprefix[i] += xprefix[i - 1];
  }

  int q;
  cin >> q;
  while (q--) {
    int m;
    cin >> m;
    if (m > 100000) {
      cout << n;
    } else {
      cout << xprefix[m];
    }
    cout << '\n';
  }
}