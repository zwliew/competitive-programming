#include <string>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {

    int strs_len = strs.size();
    int shortest_idx = -1;
    int shortest_len = -1;
    for (int i = 0; i < strs_len; i++) {
      int len = strs.at(i).length();
      if (shortest_idx == -1 || len < shortest_len) {
        shortest_idx = i;
        shortest_len = len;
      }
    }

    if (shortest_idx == -1) {
      return "";
    }

    int len = 0;
    for (auto c : strs.at(shortest_idx)) {
      bool equals = true;
      for (auto str : strs) {
        if (str.at(len) != c) {
          equals = false;
          break;
        }
      }
      if (!equals)
        break;

      len++;
    }

    return strs.at(shortest_idx).substr(0, len);
  }
};
