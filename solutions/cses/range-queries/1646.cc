#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
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

  // Since the array is static, we can simply use prefix sum queries.
  // Sum [a, b] = Sum [0, b] - Sum [0, a - 1]
  int n, q;
  cin >> n >> q;
  vector<ll> prefixSum(n);
  cin >> prefixSum[0];
  for (int i = 1; i < n; ++i) {
    cin >> prefixSum[i];
    prefixSum[i] += prefixSum[i - 1];
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << prefixSum[b - 1] - (a >= 2 ? prefixSum[a - 2] : 0) << '\n';
  }
}
