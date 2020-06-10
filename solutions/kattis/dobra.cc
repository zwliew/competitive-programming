/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

vector<vector<vector<vector<long long>>>> mem(
    101, vector<vector<vector<long long>>>(
             3, vector<vector<long long>>(3, vector<long long>(2, -1))));
unordered_set<char> vowelChars = {'A', 'E', 'I', 'O', 'U'};
long long count(string &s, int idx, int vowels, int consonants, bool found) {
  if (vowels == 3 || consonants == 3) {
    return 0;
  }
  if (idx < 0) {
    return found;
  }

  if (mem[idx][vowels][consonants][found] != -1) {
    return mem[idx][vowels][consonants][found];
  }

  if (vowelChars.count(s[idx])) {
    mem[idx][vowels][consonants][found] =
        count(s, idx - 1, vowels + 1, 0, found);
  } else if (s[idx] != '_') {
    mem[idx][vowels][consonants][found] =
        count(s, idx - 1, 0, consonants + 1, found || s[idx] == 'L');
  } else {
    mem[idx][vowels][consonants][found] =
        5 * count(s, idx - 1, vowels + 1, 0, found) +
        20 * count(s, idx - 1, 0, consonants + 1, found) +
        count(s, idx - 1, 0, consonants + 1, true);
  }
  return mem[idx][vowels][consonants][found];
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed;

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  string s;
  cin >> s;
  cout << count(s, (int)s.size() - 1, 0, 0, false);
}
