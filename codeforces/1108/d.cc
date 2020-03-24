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
  string s;
  cin >> n >> s;

  vector<vector<char>> path(200001, vector<char>(120, 0));
  vector<int> m(3);
  m[0] = s[0] != 'R';
  m[1] = s[0] != 'G';
  m[2] = s[0] != 'B';
  for (size_t i = 1; i < s.size(); ++i) {
    int a = s[i] != 'R';
    int b = s[i] != 'G';
    int c = s[i] != 'B';
    if (m[1] < m[2]) {
      a += m[1];
      path[i]['R'] = 'G';
    } else {
      a += m[2];
      path[i]['R'] = 'B';
    }
    if (m[0] < m[2]) {
      b += m[0];
      path[i]['G'] = 'R';
    } else {
      b += m[2];
      path[i]['G'] = 'B';
    }
    if (m[0] < m[1]) {
      c += m[0];
      path[i]['B'] = 'R';
    } else {
      c += m[1];
      path[i]['B'] = 'G';
    }
    m[0] = a;
    m[1] = b;
    m[2] = c;
  }

  char c;
  int x = min({m[0], m[1], m[2]});
  if (x == m[0]) {
    c = 'R';
  } else if (x == m[1]) {
    c = 'G';
  } else {
    c = 'B';
  }
  cout << x << '\n';
  string r;
  while (c) {
    r += c;
    c = path[n - 1][c];
    n--;
  }
  reverse(r.begin(), r.end());
  cout << r;
}