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

  int a, b;
  cin >> a >> b;

  int cnt = 0;
  while ((a && b) && (a > 1 || b > 1)) {
    if (b < a) {
      swap(a, b);
    }
    a += 1;
    b -= 2;
    ++cnt;
  }
  cout << cnt;
}