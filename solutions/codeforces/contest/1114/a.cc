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

  int x, y, z;
  cin >> x >> y >> z;

  int a, b, c;
  cin >> a >> b >> c;

  if (x > a) {
    cout << "NO";
    return 0;
  }

  a -= x;
  if (y > a + b) {
    cout << "NO";
    return 0;
  }

  int rest = a + c + b;
  rest -= y;

  if (z > rest) {
    cout << "NO";
  } else {
    cout << "YES";
  }
}