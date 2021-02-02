#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  string line;
  int spd = 0;
  double dist = 0;
  int last = 0;
  while (getline(cin, line)) {
    int s = (line[0] * 10 + line[1]) * 3600 + (line[3] * 10 + line[4]) * 60 +
            line[6] * 10 + line[7];
    int nxtSpd = spd;
    if (line.size() > 8) {
      nxtSpd = stoi(line.substr(8));
    }

    dist += (double)spd * (s - last) / 3600;
    last = s;

    if (spd == nxtSpd) {
      cout << line << " " << fixed << setprecision(2) << dist << " km\n";
    }
    spd = nxtSpd;
  }
}
