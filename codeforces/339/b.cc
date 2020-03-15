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

  ll n, m;
  cin >> n >> m;
  ll cur = 1;
  ll tot = 0;
  while (m--) {
    ll a;
    cin >> a;
    if (a >= cur) {
      tot += a - cur;
    } else {
      tot += n - cur + a;
    }
    cur = a;
  }
  cout << tot;
}