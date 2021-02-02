#include <bits/stdc++.h>
using namespace std;
#define debug(...) 0
#ifdef LOCAL
#include "../../_library/cc/debug.h"
#endif
// #define FILE "milkvisits"

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
#if defined(FILE) && !defined(LOCAL)
  freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
#endif

  const string dirs = "NESW";
  const vector<array<int, 2>> deltas = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int T;
  cin >> T;
  while (T--) {
    int W, H, N, M;
    cin >> W >> H >> N >> M;
    vector<array<int, 3>> robots(N);
    map<array<int, 2>, int> occupied;
    for (int i = 0; i < N; ++i) {
      int x, y;
      char d;
      cin >> x >> y >> d;
      int di = dirs.find(d);
      assert(di >= 0 && di < 4);
      robots[i] = {x, y, di};
      occupied[{x, y}] = i;
    }

    bool done = false;
    for (int i = 0; i < M; ++i) {
      int id, rep;
      char action;
      cin >> id >> action >> rep;
      if (done)
        continue;
      --id;
      if (action == 'L') {
        robots[id][2] = (robots[id][2] + 3 * rep) % 4;
      } else if (action == 'R') {
        robots[id][2] = (robots[id][2] + rep) % 4;
      } else {
        occupied.erase({robots[id][0], robots[id][1]});
        for (int j = 0; j < rep && !done; ++j) {
          robots[id][0] += deltas[robots[id][2]][0];
          robots[id][1] += deltas[robots[id][2]][1];
          array<int, 2> nxt = {robots[id][0], robots[id][1]};
          if (occupied.count(nxt)) {
            cout << "Robot " << id + 1 << " crashes into robot "
                 << occupied[nxt] + 1 << "\n";
            done = true;
          } else if (nxt[0] > W || !nxt[0] || nxt[1] > H || !nxt[1]) {
            cout << "Robot " << id + 1 << " crashes into the wall\n";
            done = true;
          }
        }
        occupied[{robots[id][0], robots[id][1]}] = id;
      }
    }

    if (!done) {
      cout << "OK\n";
    }
  }
}
