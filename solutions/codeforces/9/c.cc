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

  int sum = 0;
  for (int i = 1; i < (1 << 10); ++i) {
    int converted = 0;
    for (int j = 10; j >= 0; --j) {
      converted *= 10;
      if (i & (1 << j)) {
        converted++;
      }
    }
    if (converted <= n) {
      ++sum;
    }
  }
  cout << sum;
}