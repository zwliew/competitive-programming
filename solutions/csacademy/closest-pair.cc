#include <bits/stdc++.h>
using namespace std;

int best(vector<int>& a, vector<int>& b) {
  int res = INT_MAX;
  for (int i = 0, j = 0; i < a.size(); ++i) {
    while (j < b.size() && b[j] <= a[i])
      ++j;
    if (j) {
      res = min(res, a[i] - b[j - 1]);
    }
  }
  return res;
}

int closestPair(vector<int>& first, vector<int>& second) {
  sort(first.begin(), first.end());
  sort(second.begin(), second.end());
  return min(best(first, second), best(second, first));
}

int main() {
  int n;
  cin >> n;
  vector<int> first, second;
  for (int i = 0; i < n; ++i) {
    int val;
    cin >> val;
    first.push_back(val);
  }
  for (int i = 0; i < n; ++i) {
    int val;
    cin >> val;
    second.push_back(val);
  }
  cout << closestPair(first, second) << "\n";
  return 0;
}
