#include <bits/stdc++.h>
#include "minstack.h"
using namespace std;

int minx = 10e9 + 1;
stack<int> st;
void push(int X) {
  if (st.empty()) {
    minx = X;
    st.emplace(X);
  } else if (X >= minx) {
    st.emplace(X);
  } else {
    st.emplace(2 * X - minx);
    minx = X;
  }
}

void pop() {
  int x = st.top();
  if (x < minx) {
    minx = 2 * minx - x;
  }
  st.pop();
}

int top() {
  int x = st.top();
  return x >= minx ? x : minx;
}

int getMin() { return minx; }
