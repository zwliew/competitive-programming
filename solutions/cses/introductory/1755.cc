/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include "bits/extc++.h"

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#ifdef LOCAL
#include "../../_library/cpp/debug.h"
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

  string s;
  cin >> s;
  vector<int> freq(26);
  for (char c : s) {
    freq[c - 'A']++;
  }

  int oddCnt = 0;
  for (int i = 0; i < 26; ++i) {
    if (freq[i] % 2) ++oddCnt;
  }
  
  if (oddCnt > 1) {
    cout << "NO SOLUTION";
    return 0;
  }

  int i = 0, j = (int)s.size() - 1;
  string ans(s.size(), 0);
  for (int idx = 0; idx < 26; ++idx) {
    char c = idx + 'A';
    for (int k = i; k < i + freq[idx] / 2; ++k) {
      ans[k] = c;
    }
    i += freq[idx] / 2;
    for (int k = j; k > j - freq[idx] / 2; --k) {
      ans[k] = c;
    }
    j -= freq[idx] / 2;
  }

  for (int i = 0; i < 26; ++i) {
    if (freq[i] % 2) {
      ans[ans.size() / 2] = i + 'A';
      break;
    }
  }

  cout << ans;
}
