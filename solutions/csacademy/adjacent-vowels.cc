#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  char prev = 0;
  int n;
  cin >> n;
  int ans = 0;
  unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  while (n--) {
    char cur;
    cin >> cur;
    if (vowels.count(cur) && vowels.count(prev)) {
      ++ans;
    }
    prev = cur;
  }
  cout << ans;
}