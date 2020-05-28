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

  int l, r;
  cin >> l >> r;
  for (int i = l; i <= r; ++i) {
    bitset<10> bs;
    bool f = 0;
    int j = i;
    while (j) {
      if (bs.test(j % 10)) {
        f = 1;
        break;
      }
      bs.set(j % 10);
      j /= 10;
    }

    if (!f) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
}
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

  int l, r;
  cin >> l >> r;
  for (int i = l; i <= r; ++i) {
    bitset<10> bs;
    bool f = 0;
    int j = i;
    while (j) {
      if (bs.test(j % 10)) {
        f = 1;
        break;
      }
      bs.set(j % 10);
      j /= 10;
    }

    if (!f) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
}