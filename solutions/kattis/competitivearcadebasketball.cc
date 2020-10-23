#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
      cout << s << " wins!\n";
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, p, m;
  cin >> n >> p >> m;
  while (n--) {
    string s;
    cin >> s;
  }
  unordered_map<string, int> cnt;
  bool won = false;
  for (int i = 0; i < m; ++i) {
    string s;
    int x;
    cin >> s >> x;
    cnt[s] += x;
    if (cnt[s] >= p && cnt[s] - x < p) {
      won = true;
      cout << s << " wins!";
    }
  }
  if (!won)
    cout << "No winner!";
}

  int n, p, m;
  cin >> n >> p >> m;
  while (n--) {
    string s;
    cin >> s;
  }
  unordered_map<string, int> cnt;
  bool won = false;
  for (int i = 0; i < m; ++i) {
    string s;
    int x;
    cin >> s >> x;
    cnt[s] += x;
    if (cnt[s] >= p && cnt[s] - x < p) {
      won = true;
      cout << s << " wins!";
    }
  }
  if (!won)
    cout << "No winner!";
}
