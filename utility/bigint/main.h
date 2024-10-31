#include <utility/type.h>

#include <string>
using namespace utility;
namespace utility {
class bigint {
 private:
  // Stored as base-255 where least significant bit is at the back
  std::string data;
  // sign; true = positive
  bool sign;

  // Remove extra zeros
  void simplify() {
    std::string::iterator last = data.begin();
    for (auto it = data.begin(); it < data.end(); ++it) {
      if (*it == 0) {
        ++last;
      } else {
        data.erase(data.begin(), last);
      }
    }
  }

 public:
  bigint(const bigint &n) {
    data = n._getDataNoSimplify();
    sign = n.getSign();
  }
  bigint(LL n);
  ~bigint();

  bigint &operator=(const bigint &n) {}

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
  bool operator>=(bigint n) { return *this > n || *this == n; }
  bool operator<(bigint n) { return !(*this >= n); }
  bool operator<=(bigint n) { return !(*this > n); };
  bool operator==(bigint n) {
    simplify();
    return this->data == n.getData() && this->sign == n.getSign();
  };

  // misc
  bigint pow(const bigint &base, const bigint &exp, const bigint &mod);

  // getters
  std::string getData() {
    simplify();
    return this->data;
  }
  std::string _getDataNoSimplify() const { return this->data; }
  bool getSign() const noexcept { return this->sign; }
};
};  // namespace utility