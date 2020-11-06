#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "../../_library/cc/debug.h"
#define FILE "test"
#else
#define debug(...) 0
#define FILE ""
#endif

struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int x) : val(x), left(nullptr), right(nullptr) {}
  void insert(int x) {
    if (x < val) {
      if (left) {
        left->insert(x);
      } else {
        left = new Node(x);
      }
    } else {
      if (right) {
        right->insert(x);
      } else {
        right = new Node(x);
      }
    }
  }
};

bool same(Node* x, Node* y) {
  if (!x || !y)
    return !y && !x;
  return same(x->left, y->left) && same(x->right, y->right);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  int n, k;
  cin >> n >> k;
  vector<Node> trees;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    Node root(x);
    for (int j = 1; j < k; ++j) {
      cin >> x;
      root.insert(x);
    }

    bool found = false;
    for (int j = 0; j < trees.size() && !found; ++j) {
      found = same(&trees[j], &root);
    }
    if (!found) {
      ++cnt;
      trees.push_back(root);
    }
  }
  cout << cnt;
}
