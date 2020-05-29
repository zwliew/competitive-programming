#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> a, b;
  for (int i = 0; i < 6; ++i) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  for (int i = 0; i < 6; ++i) {
    int x;
    cin >> x;
    b.push_back(x);
  }

  int bestSum = 0;
  vector<int> probs(101);
  for (int x : a) {
    for (int y : b) {
      probs[x + y]++;
      if (probs[x + y] > probs[bestSum] ||
          (probs[x + y] == probs[bestSum] && x + y < bestSum)) {
        bestSum = x + y;
      }
    }
  }
  cout << bestSum;
}