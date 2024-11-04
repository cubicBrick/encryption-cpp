#include <cassert>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

#include "../type.h"

#pragma once
#define CHECK_T_VALID                                     \
  (assert(std::numeric_limits<utility::TStorage>::max() < \
          std::numeric_limits<LL>::max()))
#define TSTORAGE_SZ \
  (static_cast<LL>(std::numeric_limits<utility::TStorage>::max()))

namespace utility {
class bigint {
 private:
  // Least significant bit is at the back, with always 1 zero in front
  // Example (with base-255): 263 is {0, 1, 8}
  std::vector<TStorage> data;
  // sign; true = positive
  bool sign;

 public:
  bigint(const bigint &n) {
    CHECK_T_VALID;
    data = n.getData();
    sign = n.getSign();
  }
  bigint(const std::vector<TStorage> &data, const bool &sign = true);
  bigint(LL n);
  ~bigint() {}

  void operator=(const bigint &n);

  // Main operators

  bigint operator+(const bigint &n) const;
  bigint operator-(const bigint &n) const;
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
  static std::vector<TStorage> simplify(std::vector<TStorage> n);
  static bigint pow(const bigint &base, const bigint &exp, const bigint &mod);
  bool toLL(LL &res) const;
  // getters
  std::vector<TStorage> getData() const noexcept { return this->data; }
  bool getSign() const noexcept { return this->sign; }
};
};  // namespace utility