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

using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    int a, s;
    cin >> a >> s;
    v[i] = {a, s};
  }
  sort(v.begin(), v.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  int cnt = 0;
  for (auto &[a, s] : v) {
    while (pq.size() && pq.top() < a) {
      pq.pop();
    }
    if (pq.size() && pq.top() - m <= a) {
      ++cnt;
      pq.pop();
    }
    pq.emplace(a + s + m);
  }
  cout << cnt;
}
