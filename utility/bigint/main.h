#include <utility/type.h>

#include <string>
#include <vector>

#pragma once

using namespace utility;
namespace utility {
class bigint {
 private:
  // Least significant bit is at the back, with always 1 zero in front
  std::vector<TStorage> data;
  // sign; true = positive
  bool sign;

 public:
  bigint(const bigint &n) {
    data = n.getData();
    sign = n.getSign();
  }
  bigint(LL n);
  ~bigint(){}

  bigint &operator=(const bigint &n);

  // Main operators

  bigint operator+(const bigint &n) const;
  bigint operator-(const bigint &n) const { return *this + (-n); }
  bigint operator*(const bigint &n) const;
  // Preforms floor division
  bigint operator/(const bigint &n) const;
  bigint operator%(const bigint &n) const;

  // Side operators
  bigint operator-() const;

  // Assignment operators
  void operator+=(const bigint &n) { *this = *this + n; }
  void operator-=(const bigint &n) { *this = *this - n; }
  void operator*=(const bigint &n) { *this = *this * n; }
  void operator/=(const bigint &n) { *this = *this / n; }
  void operator%=(const bigint &n) { *this = *this % n; }

  // Comparison
  bool operator>(const bigint &n) const;
  bool operator>=(bigint n) const { return *this > n || *this == n; }
  bool operator<(bigint n) const { return !(*this >= n); }
  bool operator<=(bigint n) const { return !(*this > n); };
  bool operator==(bigint n) const;

  // misc
  static bigint simplify(const bigint &n);
  static bigint pow(const bigint &base, const bigint &exp, const bigint &mod);
  bool toLL(LL &res) const;
  // getters
  std::vector<TStorage> getData() const noexcept {
    return this->data;
  }
  bool getSign() const noexcept { return this->sign; }
};
};  // namespace utility