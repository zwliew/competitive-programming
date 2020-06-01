#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;
  int order[26];
  for (int i = 0; i < (int)s.size(); ++i) {
    order[s[i] - 'a'] = i;
  }
  int n;
  cin >> n;
  vector<string> v;
  while (n--) {
    string x;
    cin >> x;
    v.emplace_back(x);
  }

  sort(v.begin(), v.end(), [&](auto &l, auto &r) {
    for (int i = 0; i < min(l.size(), r.size()); ++i) {
      if ((isupper(l[i]) != 0) != (isupper(r[i]) != 0)) {
        return isupper(r[i]) != 0;
      }

      int lo = order[tolower(l[i]) - 'a'];
      int ro = order[tolower(r[i]) - 'a'];
      if (lo != ro) {
        return lo < ro;
      }
    }

    return l.size() < r.size();
  });

  for (string &x : v) {
    cout << x << '\n';
  }
}