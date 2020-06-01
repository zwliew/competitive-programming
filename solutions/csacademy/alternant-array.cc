#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n * 2];
  for (int i = 0; i < n * 2; ++i) {
    cin >> arr[i];
  }

  int a = 0, b = 0;
  for (int i = 0; i < n * 2; ++i) {
    if (i % 2) {
      a += arr[i];
      b += !arr[i];
    }
  }

  cout << min(a, b);
}