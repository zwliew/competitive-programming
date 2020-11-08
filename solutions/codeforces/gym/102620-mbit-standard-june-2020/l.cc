#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

bool lessThan(char x, char y) {
  cout << x << y << endl;
  char res;
  cin >> res;
  if (res == 'C') {
    exit(0);
  }
  return res == 'Y';
}

// Hand-written merge sort
// void mergeSort(vector<char>& a, int l, int r) {
//   if (l == r - 1) {
//     return;
//   }
//   int m = (l + r) / 2;
//   mergeSort(a, l, m);
//   mergeSort(a, m, r);
//   vector<char> res(r - l);
//   int j = l;
//   int i = m;
//   for (int k = 0; k < r - l; ++k) {
//     if (j == m || (i < r && lessThan(a[i], a[j]))) {
//       res[k] = a[i];
//       ++i;
//     } else {
//       res[k] = a[j];
//       ++j;
//     }
//   }
//   copy(res.begin(), res.end(), a.begin() + l);
// }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  vector<char> chars;
  auto addIfExists = [&](char l, char r) {
    for (char c = l; c <= r; ++c) {
      cout << c << endl;
      char res;
      cin >> res;
      if (res == 'Y') {
        chars.push_back(c);
      } else if (res == 'C') {
        exit(0);
      }
    }
  };
  addIfExists('0', '9');
  addIfExists('A', 'Z');
  addIfExists('a', 'z');

  // mergeSort(chars, 0, chars.size());
  sort(chars.begin(), chars.end(), lessThan);
  for (char c : chars)
    cout << c;
}
