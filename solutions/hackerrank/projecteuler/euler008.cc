#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int best = 0;
    for (int i = 0; i < n - k + 1; ++i) {
      int cur = 1;
      for (int j = 0; j < k; ++j) {
        cur *= s[i + j] - '0';
      }
      best = max(cur, best);
    }
    cout << best << '\n';
  }
}

