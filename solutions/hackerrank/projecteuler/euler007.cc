#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  vector<int> primes = {2};
  for (int i = 3; primes.size() < 10000; i += 2) {
    bool prime = true;
    if (i % 2) {
      for (int d = 3; d * d <= i && prime; d += 2) {
        if (i % d == 0) {
          prime = false;
        }
      }
    } else {
      prime = false;
    }
    if (prime) {
      primes.emplace_back(i);
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << primes[n - 1] << '\n';
  }
}

