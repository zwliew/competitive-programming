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

#define f first
#define s second
#define eb emplace_back

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vc = vector<char>;
using vb = vector<bool>;
using vll = vector<ll>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    string s;
    cin >> s;
    vector<stack<int>> prev(4);
    for (auto &x : prev) {
      x.emplace(s.size());
    }
    unordered_map<char, int> ctoi = {
        {'>', 0},
        {'}', 1},
        {']', 2},
        {')', 3},
    };
    unordered_map<char, char> ctoc = {
        {'<', '>'},
        {'{', '}'},
        {'(', ')'},
        {'[', ']'},
    };
    vi ans(s.size() + 1);
    for (int i = (int)s.size(); ~i; --i) {
      if (ctoi.count(s[i])) {
        prev[ctoi[s[i]]].emplace(i);
      } else {
        int closingIdx = prev[ctoi[ctoc[s[i]]]].top();
        bool ok = closingIdx < (int)s.size();
        for (int j = 0; j < 4 && ok; ++j) {
          if (prev[j].top() < closingIdx) {
            ok = false;
          }
        }

        if (ok) {
          ans[i] = ans[closingIdx + 1] + closingIdx - i + 1;
          prev[ctoi[ctoc[s[i]]]].pop();
        } else {
          prev = vector<stack<int>>(4);
          for (auto &x : prev) {
            x.emplace(s.size());
          }
        }
      }
    }

    cout << "Case " << ti << ":\n";
    ans.pop_back();
    for (int x : ans) {
      cout << x << '\n';
    }
  }
}
