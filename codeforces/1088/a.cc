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

  int x;
  cin >> x;

  // for (int a = 1; a <= x; ++a) {
  //   for (int b = 1; b <= x; ++b) {
  //     if (a % b == 0 && a * b > x && a / b < x) {
  //       cout << a << ' ' << b;
  //       return 0;
  //     }
  //   }
  // }
  // cout << -1;

  if (x == 1) {
    cout << -1;
  } else {
    cout << x - x % 2 << ' ' << 2;
  }
}