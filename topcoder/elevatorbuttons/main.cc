#include <bits/stdc++.h>
using namespace std;

class ElevatorButtons {
 public:
  vector<int> nextStops(int currentFloor, int currentDirection,
                        vector<int> buttonsPressed) {
    unordered_set<int> floors;
    for (int i : buttonsPressed) {
      floors.emplace(i);
    }

    vector<int> res;

    if (currentDirection == 1) {
      for (int i = currentFloor; i < 1001; ++i) {
        if (floors.count(i)) {
          res.push_back(i);
          floors.erase(i);
        }
      }
      for (int i = 1000; i >= 0; --i) {
        if (floors.count(i)) {
          res.push_back(i);
          floors.erase(i);
        }
      }
    } else {
      for (int i = currentFloor; i >= 0; --i) {
        if (floors.count(i)) {
          res.push_back(i);
          floors.erase(i);
        }
      }
      for (int i = 0; i < 1001; ++i) {
        if (floors.count(i)) {
          res.push_back(i);
          floors.erase(i);
        }
      }
    }

    return res;
  }
};