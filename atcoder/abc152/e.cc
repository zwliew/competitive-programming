#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
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

const int MOD = 1e9 + 7;

int mpow(int base, int exp) {
  int res = 1;
  while (exp) {
    if (exp & 1) {
      res = ((ll)res * base) % MOD;
    }
    base = ((ll)base * base) % MOD;
    exp /= 2;
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a;
  unordered_map<int, int> answer;
  while (n--) {
    int x;
    cin >> x;
    a.push_back(x);
    unordered_map<int, int> cnt;
    for (int i = 2; i * i <= x; ++i) {
      while (x % i == 0) {
        ++cnt[i];
        x /= i;
      }
    }
    if (x != 1) {
      ++cnt[x];
    }

    for (auto i : cnt) {
      answer[i.first] = max(answer[i.first], i.second);
    }
  }

  int lcm = 1;
  for (auto i : answer) {
    for (int j = 0; j < i.second; ++j) {
      lcm = ((ll)lcm * i.first) % MOD;
    }
  }

  int sum = 0;
  for (int x : a) {
    cerr << "x=" << x << " mpow(x, MOD - 2)=" << mpow(x, MOD - 2) << '\n';
    sum = (sum + (ll)lcm * mpow(x, MOD - 2)) % MOD;
  }
  cout << sum;
}
