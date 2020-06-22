#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  vector<int> computed;
  for (int i = 100; i <= 999; ++i) {
    for (int j = i; j <= 999; ++j) {
      int cur = i * j;
      string x = to_string(cur);
      string y = x;
      reverse(y.begin(), y.end());
      if (x == y) {
        computed.emplace_back(cur);
      }
    }
  }
  sort(computed.begin(), computed.end());

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    auto it = lower_bound(computed.begin(), computed.end(), n);
    cout << *prev(it) << '\n';
  }
}

