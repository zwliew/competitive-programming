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

  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    queue<char> dq;
    for (int i = 0; i < b; ++i) {
      dq.emplace(i + 'a');
    }
    for (int i = 0; i < a - b; ++i) {
      dq.emplace('a');
    }
    string ans;
    while (ans.size() < n) {
      ans += dq.front();
      dq.emplace(dq.front());
      dq.pop();
    }
    cout << ans << '\n';
  }
}
