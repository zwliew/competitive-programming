#include <iostream>
#include <numeric>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int cgcd;
  int arr[n];
  cin >> arr[0];
  cgcd = arr[0];
  for (int i = 1; i < n; ++i) {
    cin >> arr[i];
    cgcd = gcd(arr[i], cgcd);
  }

  for (int i = 0; i < m; ++i) {
    int idx, val;
    cin >> idx >> val;
    --idx;
    arr[idx] /= val;
    cgcd = gcd(cgcd, arr[idx]);
    cout << cgcd << '\n';
  }
}