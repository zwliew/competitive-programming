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

  int tot = 0;
  if (n >= 100) {
    tot += n / 100;
    n -= n / 100 * 100;
  }
  if (n >= 20) {
    tot += n / 20;
    n -= n / 20 * 20;
  }
  if (n >= 10) {
    tot += n / 10;
    n -= n / 10 * 10;
  }
  if (n >= 5) {
    tot += n / 5;
    n -= n / 5 * 5;
  }
  tot += n;
  cout << tot;
}