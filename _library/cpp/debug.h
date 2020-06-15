#include <bitset>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

std::string to_string(char c) { return std::string(1, c); }

std::string to_string(std::string s) { return '"' + s + '"'; }

std::string to_string(const char *s) { return to_string((std::string)s); }

std::string to_string(bool b) { return (b ? "true" : "false"); }

std::string to_string(std::vector<bool> v) {
  std::string res = "{";
  for (int i = 0; i < (int)v.size(); ++i) {
    res += char('0' + v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
std::string to_string(std::bitset<N> b) {
  std::string res = "";
  for (int i = 0; i < N; ++i) {
    res += char('0' + b[i]);
  }
  return res;
}

template <typename A, typename B>
std::string to_string(std::pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
std::string to_string(std::tuple<A, B, C> t) {
  return "(" + to_string(std::get<0>(t)) + ", " + to_string(std::get<1>(t)) +
         ", " + to_string(std::get<2>(t)) + ")";
}

template <typename A, typename B, typename C, typename D>
std::string to_string(std::tuple<A, B, C, D> t) {
  return "(" + to_string(std::get<0>(t)) + ", " + to_string(std::get<1>(t)) +
         ", " + to_string(std::get<2>(t)) + ", " + to_string(std::get<3>(t)) +
         ")";
}

template <typename A>
std::string to_string(A v) {
  bool first = true;
  std::string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += '}';
  return res;
}

void _debug() { std::cerr << '\n'; }

template <typename Head, typename... Tail>
void _debug(Head H, Tail... T) {
  std::cerr << ' ' << to_string(H);
  _debug(T...);
}

#define debug(...) std::cerr << '[' << #__VA_ARGS__ << "]:", _debug(__VA_ARGS__)