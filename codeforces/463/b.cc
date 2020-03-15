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
  int ch = 0;
  int ce = 0;
  int cm = 0;
  while (n--) {
    int h;
    cin >> h;
    ce += ch - h;
    if (ce < 0) {
      cm -= ce;
      ce = 0;
    }
    ch = h;
  }
  cout << cm;
}