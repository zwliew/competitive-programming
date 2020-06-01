#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int count = 0;
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    count += p;
  }
  cout << (count % 2);
}