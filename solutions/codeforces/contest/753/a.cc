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

  int n;
  cin >> n;

  int cur = 1;
  while (n >= cur) {
    n -= cur;
    ++cur;
  }
  cout << cur - 1 << '\n';
  for (int i = 1; i < cur - 1; ++i) {
    cout << i << ' ';
  }
  cout << cur + n - 1;
}