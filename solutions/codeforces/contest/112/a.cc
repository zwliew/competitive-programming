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

  string a, b;
  cin >> a >> b;
  transform(a.begin(), a.end(), a.begin(), [](auto c) { return tolower(c); });
  transform(b.begin(), b.end(), b.begin(), [](auto c) { return tolower(c); });

  if (a < b) {
    cout << -1;
  } else if (a == b) {
    cout << 0;
  } else {
    cout << 1;
  }
}