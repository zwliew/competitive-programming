#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define LOCAL
#ifdef LOCAL
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", _debug(__VA_ARGS__)
#else
#define debug(...) 0
#endif

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
  return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " +
         to_string(get<2>(t)) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += '}';
  return res;
}

void _debug() { cerr << '\n'; }
template <typename Head, typename... Tail>
void _debug(Head H, Tail... T) {
  cerr << ' ' << to_string(H);
  _debug(T...);
}

#define eb emplace_back

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vc = vector<char>;
using vb = vector<bool>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

  int n;
  while (cin >> n && n) {
    vi arr(n);
    for (auto &x : arr) cin >> x;

    vi parent(n, -1);
    vii dp = {{-1e9, -1}};

    for (int i = 0; i < n; ++i) {
      auto it = lower_bound(dp.begin(), dp.end(), make_pair(arr[i], 0));
      if (it == dp.end()) {
        parent[i] = dp.back().second;
        dp.emplace_back(arr[i], i);
      } else {
        it->first = arr[i];
        it->second = i;
        parent[i] = prev(it)->second;
      }
    }

    cout << dp.size() - 1 << ' ';
    int idx = dp.back().second;
    vi output;
    while (idx != -1) {
      output.eb(arr[idx]);
      idx = parent[idx];
    }
    reverse(output.begin(), output.end());
    for (auto x : output) cout << x << ' ';
    cout << '\n';
  }

  // Alternative O(n^2) solution.
  // Max input size <= 200 * 200. Use O(n^2) LIS.
  // int n;
  // while (cin >> n && n) {
  //   vi arr(n);
  //   for (auto &x : arr) cin >> x;

  //   vi parent(n, -1);
  //   vi dp(n);
  //   dp[0] = 1;
  //   vi bestIndices = {0};
  //   for (int i = 1; i < n; ++i) {
  //     for (int j = 0; j < i; ++j) {
  //       if (arr[j] < arr[i]) {
  //         if (dp[j] > dp[i]) {
  //           dp[i] = dp[j];
  //           parent[i] = j;
  //         } else if (dp[j] == dp[i] && arr[j] < arr[parent[i]]) {
  //           parent[i] = j;
  //         }
  //       }
  //     }
  //     ++dp[i];

  //     if (dp[i] > dp[bestIndices[0]]) {
  //       bestIndices = {i};
  //     } else if (dp[i] == dp[bestIndices[0]]) {
  //       bestIndices.emplace_back(i);
  //     }
  //   }

  //   vector<vi> outputs;
  //   for (int idx : bestIndices) {
  //     outputs.emplace_back(vi());
  //     while (idx != -1) {
  //       outputs.back().emplace_back(arr[idx]);
  //       idx = parent[idx];
  //     }
  //   }
  //   sort(outputs.begin(), outputs.end());

  //   cout << outputs[0].size() << ' ';
  //   for (int i = outputs[0].size() - 1; i >= 0; --i) {
  //     cout << outputs[0][i] << ' ';
  //   }
  //   cout << '\n';
  // }
}
