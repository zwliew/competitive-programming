#include <bits/stdc++.h>
#include "middlenumber.h"

using namespace std;

multiset<int, greater<int>> maxq;
multiset<int> minq;

void balance() {
  if (maxq.size() < minq.size()) {
    maxq.emplace(*(minq.begin()));
    minq.erase(minq.begin());
  } else if (maxq.size() > minq.size() + 1) {
    minq.emplace(*(maxq.begin()));
    maxq.erase(maxq.begin());
  }
}

void push(int x) {
  if (!minq.empty() && x > *(minq.begin())) {
    minq.emplace(x);
  } else {
    maxq.emplace(x);
  }
  balance();
}

int median() {
  if (maxq.size() > minq.size()) {
    return *(maxq.begin());
  }
  return *maxq.begin() + (*minq.begin() - *maxq.begin()) / 2;
}

int init(int* arr, int length) {
  for (int i = 0; i < length; ++i) {
    push(arr[i]);
  }
  return median();
}

int add_number(int x) {
  push(x);
  return median();
}

int remove_number(int x) {
  auto it = maxq.find(x);
  if (it == maxq.end()) {
    minq.erase(minq.find(x));
  } else {
    maxq.erase(it);
  }
  balance();
  return median();
}

int change_number(int oldx, int newx) {
  auto it = maxq.find(oldx);
  if (it == maxq.end()) {
    minq.erase(minq.find(oldx));
  } else {
    maxq.erase(it);
  }
  return add_number(newx);
}
