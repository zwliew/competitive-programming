#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ef emplace_front
#define eb emplace_back
#define mp make_pair
#define MOD 1000000007

typedef long double f80;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<vb> vvb;
typedef float f32;
typedef double f64;
typedef long double f80;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  char c;
  cin >> n;

  ll a = 0, b = 0;
  ll psum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> c;
    psum = psum + tolower(c) - 'a' + 1;
    if (i & 1)
      a += psum;
    else
      b += psum;
  }
  if (n & 1)
    cout << b << ' ' << a;
  else
    cout << a << ' ' << b;
}