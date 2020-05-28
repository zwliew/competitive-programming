#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
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

// vector<ld> ans(1000001);
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Digits of n = floor(log10(n)) + 1
  // Memoise the results of log10(n!) = log10((n - 1)!) + log10(n)

  // ans[0] = ans[1] = 0;
  // for (int i = 2; i <= 1000000; ++i) {
  //   ans[i] = ans[i - 1] + log10l(i);
  // }

  // int n;
  // while (cin >> n) {
  //   cout << (int)ans[n] + 1 << '\n';
  // }

  // Alternative (simpler) solution using the lgamma function
  int n;
  while (cin >> n) {
    cout << (int)(lgammal(n + 1) / logl(10)) + 1 << '\n';
  }
}
