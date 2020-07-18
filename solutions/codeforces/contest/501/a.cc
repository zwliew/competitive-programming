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

  ld a, b, c, d;
  cin >> a >> b >> c >> d;

  ld x = max(a * 3 / 10, a - a / 250 * c);
  ld y = max(b * 3 / 10, b - b / 250 * d);
  if (x == y) {
    cout << "Tie";
  } else if (x > y) {
    cout << "Misha";
  } else {
    cout << "Vasya";
  }
}