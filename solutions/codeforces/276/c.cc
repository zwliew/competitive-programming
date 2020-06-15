/*
ID: zhaowei10
TASK:
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 0
#endif

template <typename T>
struct DifferenceArray {
  std::vector<T> diff, accumulated;
  bool done = false;

  DifferenceArray(size_t n) : diff(n + 1) {}

  bool update(int l, int r, T val) {
    if (accumulated.size()) return false;
    diff[l] += val;
    diff[r + 1] -= val;
    return true;
  }

  // Only accumulate once
  std::vector<T> accumulate() {
    if (accumulated.empty()) {
      partial_sum(diff.begin(), diff.end() - 1,
                  std::back_inserter(accumulated));
    }
    return accumulated;
  }

  T query(int idx) { return accumulated[idx]; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

#ifdef LOCAL
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#else
#endif

  int n, q;
  cin >> n >> q;
  vector<int> arr(n);
  for (auto &x : arr) cin >> x;

  DifferenceArray<int> diff(n);
  while (q--) {
    int l, r;
    cin >> l >> r;
    diff.update(l - 1, r - 1, 1);
  }

  auto freq = diff.accumulate();

  sort(arr.begin(), arr.end());
  sort(freq.begin(), freq.end());

  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += 1ll * freq[i] * arr[i];
  }
  cout << sum;
}
