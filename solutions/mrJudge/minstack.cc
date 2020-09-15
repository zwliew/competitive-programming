#include "minstack.h"
#include <bits/stdc++.h>
using namespace std;

stack<int> cur, mn;

void push(int X) {
  cur.push(X);
  mn.push(min(X, mn.empty() ? INT_MAX : mn.top()));
}

void pop() {
  cur.pop();
  mn.pop();
}

int top() {
  return cur.top();
}

int getMin() {
  return mn.top();
}