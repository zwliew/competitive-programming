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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  if (fopen(FILE ".in", "r")) {
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
  }

  unordered_map<int, string> freqToPitch = {
      {44000, "A"},  {46616, "A#"}, {49388, "B"},  {52325, "C"},
      {55437, "C#"}, {58733, "D"},  {62225, "D#"}, {65926, "E"},
      {69846, "F"},  {73999, "F#"}, {78399, "G"},  {83061, "G#"},
  };
  unordered_map<string, unordered_set<string>> keyToPitch = {
      {"G major", {"G", "A", "B", "C", "D", "E", "F#"}},
      {"C major", {"C", "D", "E", "F", "G", "A", "B"}},
      {"Eb major", {"D#", "F", "G", "G#", "A#", "C", "D"}},
      {"F# minor", {"F#", "G#", "A", "B", "C#", "D", "E"}},
      {"G minor", {"G", "A", "A#", "C", "D", "D#", "F"}},
      {"Eb major", {"D#", "F", "G", "G#", "A#", "C", "D"}},
  };
  unordered_map<string, string> altPitch = {
      {"A#", "Bb"}, {"C#", "Db"}, {"D#", "Eb"}, {"F#", "Gb"}, {"G#", "Ab"},
  };
  unordered_map<string, unordered_set<string>> keyReps = {
      {"Eb major", {"D#", "G#", "A#"}},
      {"G minor", {"A#", "D#"}},
  };

  int n;
  cin >> n;
  vector<string> pitches;
  unordered_set<string> uniquePitches;
  while (n--) {
    double x;
    cin >> x;
    while (x > 850) {
      x /= 2;
    }
    while (x < 420) {
      x *= 2;
    }
    int origFreq = x * 100;
    int freq;
    for (freq = origFreq - 1; freq <= origFreq + 1 && !freqToPitch.count(freq);
         ++freq)
      ;
    pitches.push_back(freqToPitch[freq]);
    uniquePitches.insert(freqToPitch[freq]);
  }

  vector<string> possibleKeys;
  for (auto& [key, allowedPitches] : keyToPitch) {
    bool ok = true;
    for (auto& x : uniquePitches) {
      if (!allowedPitches.count(x)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      possibleKeys.push_back(key);
    }
  }

  if (possibleKeys.size() != 1) {
    cout << "cannot determine key";
    return 0;
  }

  cout << possibleKeys[0] << "\n";
  for (int i = 0; i < pitches.size(); ++i) {
    if (keyReps[possibleKeys[0]].count(pitches[i])) {
      pitches[i] = altPitch[pitches[i]];
    }
    cout << pitches[i] << "\n";
  }
}
