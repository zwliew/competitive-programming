#include <stdio.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int, int>;

#define eb emplace_back

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // SSSP using vertices labelled via strings
  vector<string> order;
  unordered_map<string, vector<string>> adj;
  string author;
  while (cin >> author) {
    order.eb(author);
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<string> coauthors{istream_iterator<string>(iss),
                             istream_iterator<string>()};
    for (string coauthor : coauthors) {
      adj[author].eb(coauthor);
      adj[coauthor].eb(author);
    }
  }

  queue<string> q;
  unordered_map<string, int> dist;
  dist["PAUL_ERDOS"] = 0;
  q.emplace("PAUL_ERDOS");
  while (q.size()) {
    string u = q.front();
    q.pop();
    int ndist = dist[u] + 1;
    for (string v : adj[u]) {
      if (dist.count(v)) continue;
      dist[v] = ndist;
      q.emplace(v);
    }
  }

  for (string x : order) {
    cout << x << ' ';
    if (dist.count(x)) {
      cout << dist[x];
    } else {
      cout << "no-connection";
    }
    cout << '\n';
  }
}
