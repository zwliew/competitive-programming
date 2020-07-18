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
  if (!a) {
    return b;
  }
  return gcd(b, a % b);
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int k, r;
  cin >> k >> r;

  for (int i = 1; i < k * 10; ++i) {
    if (!((k * i) % 10) || !((k * i - r) % 10)) {
      cout << i;
      return 0;
    }
  }
}