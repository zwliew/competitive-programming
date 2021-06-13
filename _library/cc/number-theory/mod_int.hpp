template <int _MOD>
class mod_int {
  static constexpr int MOD = _MOD;
  static_assert(_MOD > 0, "MOD must be positive");

 private:
  int v;

 public:
  mod_int() : v(0) {}
  mod_int(int64_t _v) : v(_v % MOD) {
    if (v < 0) {
      v += MOD;
    }
  }

  explicit operator int() const { return v; }

  friend std::istream& operator>>(std::istream& in, mod_int& x) {
    int64_t _v;
    in >> _v;
    x = mod_int(_v);
    return in;
  }

  friend std::ostream& operator<<(std::ostream& out, const mod_int& x) {
    return out << int(x);
  }

  friend bool operator==(const mod_int& x, const mod_int& y) {
    return x.v == y.v;
  }

  friend bool operator!=(const mod_int& x, const mod_int& y) {
    return x.v != y.v;
  }

  friend mod_int operator+(const mod_int& x, const mod_int& y) {
    return mod_int(x) += y;
  }

  friend mod_int operator-(const mod_int& x, const mod_int& y) {
    return mod_int(x) -= y;
  }

  friend mod_int operator*(const mod_int& x, const mod_int& y) {
    return mod_int(x) *= y;
  }

  friend mod_int operator--(mod_int& x, int) {
    mod_int res(x);
    --x;
    return res;
  }

  friend mod_int operator++(mod_int& x, int) {
    mod_int res(x);
    ++x;
    return res;
  }

  mod_int operator+() const { return mod_int(*this); }

  mod_int operator-() const { return mod_int(-v); }

  mod_int& operator++() { return *this += 1; }

  mod_int& operator--() { return *this -= 1; }

  mod_int& operator+=(const mod_int& x) {
    v -= MOD - x.v;
    if (v < 0) {
      v += MOD;
    }
    return *this;
  }

  mod_int& operator-=(const mod_int& x) {
    v -= x.v;
    if (v < 0) {
      v += MOD;
    }
    return *this;
  }

  mod_int& operator*=(const mod_int& x) {
    v = (int64_t(v) * x.v) % MOD;
    return *this;
  }
};