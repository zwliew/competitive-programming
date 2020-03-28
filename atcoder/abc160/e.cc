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

  ll x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<ll> p(a), q(b), r(c);
  for (ll &x : p) cin >> x;
  for (ll &x : q) cin >> x;
  for (ll &x : r) cin >> x;
  sort(p.rbegin(), p.rend());
  sort(q.rbegin(), q.rend());
  sort(r.rbegin(), r.rend());
  priority_queue<ll> pq;
  for (int i = 0; i < x; ++i) {
    pq.emplace(-p[i]);
  }
  for (int i = 0; i < y; ++i) {
    pq.emplace(-q[i]);
  }
  for (ll t : r) {
    if (t > -pq.top()) {
      pq.pop();
      pq.emplace(-t);
    } else {
      break;
    }
  }
  ll tot = 0;
  while (pq.size()) {
    tot -= pq.top();
    pq.pop();
  }
  cout << tot;
}
