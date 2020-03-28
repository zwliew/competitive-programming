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
  while (t--) {
    int a, b;
    cin >> a >> b;
    bool f = 0;

    // Binary search for a multiple of 2 that works
    // int lo = 0, hi = a / 2;
    // while (lo <= hi) {
    //   int twos = lo + (hi - lo) / 2;
    //   int ones = a - twos * 2;
    //   int cur = ones * 2 + twos;
    //   if (cur == b) {
    //     f = 1;
    //     break;
    //   }
    //   if (cur < b) {
    //     hi = twos - 1;
    //   } else {
    //     lo = twos + 1;
    //   }
    // }

    // Mathematical analysis solution
    if (a > b) swap(a, b);
    f = (a + b) % 3 == 0 && a * 2 >= b;

    if (f) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
}