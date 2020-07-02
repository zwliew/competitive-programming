#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  const string target = "Jane Eyre";
  int64_t n, m, k;
  cin >> n >> m >> k;
  priority_queue<pair<string, int64_t>, vector<pair<string, int64_t>>,
                 greater<pair<string, int64_t>>>
      q;
  q.emplace(target, k);
  int64_t cur = 0;

  string line;
  getline(cin, line);
  for (int i = 0; i < n; ++i) {
    getline(cin, line);
    int ck;
    string cs;
    string prev;
    stringstream ss(line);
    while (ss >> line) {
      cs += " " + prev;
      prev = line;
    }
    ck = stoi(line);
    cs = cs.substr(3, cs.size() - 4);
    q.emplace(cs, ck);
  }

  vector<tuple<int64_t, string, int64_t>> books;
  for (int i = 0; i < m; ++i) {
    getline(cin, line);
    stringstream ss(line);
    int ct, ck;
    bool first = false;
    string prev;
    string cs;
    while (ss >> line) {
      if (!first) {
        first = true;
        ct = stoi(line);
      } else {
        cs += " " + prev;
        prev = line;
      }
    }
    ck = stoi(line);
    cs = cs.substr(3, cs.size() - 4);
    if (!ct) {
      q.emplace(cs, ck);
    } else {
      books.emplace_back(ct, cs, ck);
    }
  }
  sort(books.rbegin(), books.rend());

  while (q.size() || books.size()) {
    if (q.empty()) {
      auto [ct, cs, ck] = books.back();
      books.pop_back();
      cur = ct;
      q.emplace(cs, ck);
      continue;
    }

    while (books.size() && get<0>(books.back()) <= cur) {
      auto [_, cs, ck] = books.back();
      q.emplace(cs, ck);
      books.pop_back();
    }

    auto [title, dur] = q.top();
    q.pop();

    if (title == target) {
      cout << dur + cur;
      return 0;
    }

    cur += dur;
  }
}