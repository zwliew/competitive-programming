#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  uint32_t l;
  cin >> l;

  vector<int32_t> v(l);
  for (uint32_t li = 0; li < l; ++li) {
    cin >> v[li];
  }

  sort(v.begin(), v.end());

  uint32_t q;
  cin >> q;
  for (uint32_t qi = 0; qi < q; ++qi) {
    int32_t x;
    cin >> x;

    auto lb = lower_bound(v.begin(), v.end(), x);
    auto ub = upper_bound(v.begin(), v.end(), x);

    cout << "Smaller: " << (lb - v.begin()) << ", Greater: " << (v.end() - lb) << '\n';
  }
}