#include <iostream>

using namespace std;

int main() {
  int x1, x2, x3;
  cin >> x1 >> x2 >> x3;
  cout << min(abs(x3 - x1), abs(x3 - x2)) + abs(x2 - x1);
}