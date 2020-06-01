#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  set<pair<int, int>> bst;
  for (int j = 0; j < k; ++j) {
    bst.emplace(arr[j], -j);
  }
  for (int i = 0; i < n; ++i) {
    bst.erase(bst.find({arr[i], -i}));
    if (i + k < n) {
      bst.emplace(arr[i + k], -i - k);
    }
    auto it = bst.begin();
    if (it != bst.end() && it->first < arr[i]) {
      swap(arr[i], arr[-(it->second)]);
      break;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << arr[i] << ' ';
  }
}