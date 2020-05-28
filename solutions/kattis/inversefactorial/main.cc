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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // Memoise the results of log10(n!) = log10((n - 1)!) + log10(n)
  unordered_map<int, int> m;
  // ld prev = 0;
  // for (int i = 2; i <= 6; ++i) {
  //   prev += log10l(i);
  // }
  // for (int i = 7; i <= 1000000; ++i) {
  //   ld next = prev + log10l(i);
  //   m[(int)next + 1] = i;
  //   prev = next;
  // }

  // Alternative method of computing number of digits in n! using lgamma
  for (int i = 7; i <= 1000000; ++i) {
    int digits = (int)(lgamma(i + 1) / log(10)) + 1;
    m[digits] = i;
  }

  string s;
  cin >> s;
  if (s == "1")
    cout << 1;
  else if (s == "2")
    cout << 2;
  else if (s == "6")
    cout << 3;
  else if (s == "24")
    cout << 4;
  else if (s == "120")
    cout << 5;
  else if (s == "720")
    cout << 6;
  else {
    cout << m[s.size()];
  }
}
