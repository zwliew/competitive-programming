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

  string a, b, c;
  cin >> a >> b >> c;
  a += b;
  sort(a.begin(), a.end());
  sort(c.begin(), c.end());
  if (a == c) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}