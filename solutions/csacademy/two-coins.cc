#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  bool ok[21];
  memset(ok, 0, sizeof ok);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ok[arr[i] + arr[j]] = true;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= 20; ++i) {
    if (ok[i]) ++cnt;
  }
  cout << cnt;
}