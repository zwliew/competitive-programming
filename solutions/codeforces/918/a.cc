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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int a = 1, b = 1;
  while (b <= n) {
    cout << 'O';
    int tmp = a + b;
    a = b;
    for (int i = b + 1; i < min(tmp, n + 1); ++i) {
      cout << 'o';
    }
    b = tmp;
  }
}