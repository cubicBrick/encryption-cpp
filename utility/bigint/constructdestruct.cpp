#include "main.h"

utility::bigint::bigint(LL n) {
    CHECK_T_VALID;
    sign = (n >= 0);
    if (n < 0) n = -n;
    while (n > 0) {
      data.push_back(static_cast<TStorage>(n % BASE));
      n /= BASE;
    }

    if (data.empty()) {
      data.push_back(0);
      sign = true;
    }
}