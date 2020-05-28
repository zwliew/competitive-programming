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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // ll q;
  // cin >> q;
  // while (q--) {
  //   ll n;
  //   cin >> n;
  //   int cnt = 0;
  //   while (n != 1) {
  //     if (n % 2 == 0) {
  //       n /= 2;
  //     } else if (n % 3 == 0) {
  //       n = 2 * n / 3;
  //     } else if (n % 5 == 0) {
  //       n = 4 * n / 5;
  //     } else {
  //       cout << -1 << '\n';
  //       break;
  //     }
  //     ++cnt;
  //   }
  //   if (n == 1) {
  //     cout << cnt << '\n';
  //   }
  // }

  int q;
  cin >> q;
  while (q--) {
    ll n;
    cin >> n;

    int cnt = 0;
    while (n % 2 == 0) {
      n >>= 1;
      ++cnt;
    }

    while (n % 3 == 0) {
      n /= 3;
      cnt += 2;
    }

    while (n % 5 == 0) {
      n /= 5;
      cnt += 3;
    }

    if (n == 1) {
      cout << cnt << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
}