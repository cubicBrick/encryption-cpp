#include "main.h"

utility::bigint::bigint(LL n) {
    CHECK_T_VALID;
    sign = (n >= 0);
    if (n < 0) n = -n;
    while (n > 0) {
      data.push_back(static_cast<TStorage>(n % TSTORAGE_SZ));
      n /= TSTORAGE_SZ;
    }
    data.push_back(0);
    std::reverse(data.begin(), data.end());
}

utility::bigint::bigint(const std::vector<utility::TStorage> &data, const bool &sign){
  this->sign = sign;
  this->data = utility::bigint::simplify(data);
}