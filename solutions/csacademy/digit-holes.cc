#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int best = 0;
  int smallest = a;
  for (int i = a; i <= b; ++i) {
    int count = 0;
    int j = i;
    do {
      int dig = j % 10;
      if (dig == 0 || dig == 6 || dig == 9) {
        ++count;
      } else if (dig == 8) {
        count += 2;
      }
      j /= 10;
    } while (j);
    if (count > best) {
      best = count;
      smallest = i;
    }
  }

  cout << smallest;
}