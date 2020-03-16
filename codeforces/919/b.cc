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

  int k;
  cin >> k;

  int curk = 0;
  int curval = 0;
  while (curk < k) {
    int csum = 0;
    int tmp = curval;
    while (tmp) {
      csum += tmp % 10;
      tmp /= 10;
    }

    if (csum == 10) {
      curk++;
    }
    curval++;
  }
  cout << curval - 1;
}