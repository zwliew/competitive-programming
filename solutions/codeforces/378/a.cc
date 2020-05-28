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

  int a, b;
  cin >> a >> b;

  int wcnt = 0, dcnt = 0, lcnt = 0;
  for (int i = 1; i <= 6; ++i) {
    if (abs(a - i) == abs(b - i)) {
      ++dcnt;
    } else if (abs(a - i) > abs(b - i)) {
      ++lcnt;
    } else {
      ++wcnt;
    }
  }
  cout << wcnt << ' ' << dcnt << ' ' << lcnt;
}