/**
 * Problem:
 * https://leetcode.com/problems/number-of-operations-to-make-network-connected
 *
 * Disjoint sets solution
 *
 * Time complexity: O(V+E)
 * Space complexity: O(V)
 *
 * Accepted as maximum V == 10^5 and maximum E == 10^5
 */
class Solution {
 private:
  int findSet(vector<int> &parents, int a) {
    return parents[a] == a ? a : (parents[a] = findSet(parents, parents[a]));
  }

 public:
  int makeConnected(int n, vector<vector<int>> &connections) {
    if (connections.size() < n - 1) return -1;

    int numSets = n;
    vector<int> parents(n);
    iota(parents.begin(), parents.end(), 0);

    for (int i = 0; i < connections.size(); ++i) {
      int a = connections[i][0];
      int b = connections[i][1];
      if (findSet(parents, a) != findSet(parents, b)) {
        parents[findSet(parents, a)] = findSet(parents, b);
        --numSets;
      }
    }
    return numSets - 1;
  }
};