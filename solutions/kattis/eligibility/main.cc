#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--) {
    string nm, ps, bd;
    int cs;
    cin >> nm >> ps >> bd >> cs;

    if (ps[2] >= '1' || bd[0] >= '2' ||
        (bd[1] == '9' && bd[2] == '9' && bd[3] >= '1')) {
      cout << nm << " eligible\n";
      continue;
    }

    if (cs > 40) {
      cout << nm << " ineligible\n";
      continue;
    }

    cout << nm << " coach petitions\n";
  }
}