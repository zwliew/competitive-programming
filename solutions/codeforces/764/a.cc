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

int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, m, z;
  cin >> n >> m >> z;

  // int a = n, b = m;
  // int cnt = 0;
  // while (a <= z && b <= z) {
  //   if (a == b) {
  //     ++cnt;
  //     a += n;
  //     b += m;
  //   } else if (a < b) {
  //     a += n;
  //   } else {
  //     b += m;
  //   }
  // }
  // cout << cnt;

  cout << floor(z / lcm(n, m));
}