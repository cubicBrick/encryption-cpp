#include "main.h"

inline void utility::bigint::operator=(const bigint& n) {
  this->data = bigint::simplify(n).data;
  this->sign = n.getSign();
}

utility::bigint utility::bigint::operator+(const bigint& n) const {
  if (this->sign && !n.getSign()) return *this - (-n);
  if (!this->sign && n.getSign()) return n - (-*this);
  if (!this->sign && !n.getSign()) return -(-*this + (-n));
  std::vector<TStorage> nData = n.getData();
  if (nData.size() > this->data.size()) {
    return n + *this;
  }
  LL tsz = this->data.size();
  LL nsz = nData.size();
  std::vector<TStorage> res(tsz + 1);
  LL carry = 0;
  // Current number has more digits for sure
  for (LL i = 0; i < tsz; ++i) {
    if (i < nsz) {
      LL _sum = carry + nData[nsz - 1 - i] + this->data[tsz - 1 - i];
      if (_sum < TSTORAGE_SZ) {
        res[tsz - i] = _sum;
        carry = 0;
      } else {
        res[tsz - i] = _sum - TSTORAGE_SZ;
        carry = 1;
      }
    } else {
      res[tsz - i] = this->data[tsz - 1 - i] + carry;
      carry = 0;
    }
  }
  return simplify(bigint(res, true));
}

utility::bigint utility::bigint::operator-(const bigint& n) const {
  if (!this->sign && !n.getSign()) return -(-n - (-*this));
  if (this->sign && !n.getSign()) return *this + (-n);
  if (!this->sign && n.getSign()) return -(-*this - n);
  if (n > *this) return -(n - *this);
  if (n == *this) return bigint(0);
  LL tsz = this->data.size();
  const std::vector<TStorage> nData = n.getData();
  const std::vector<TStorage> tData = this->data;
  LL nsz = nData.size();
  std::vector<TStorage> res(tsz);
  LL carry = 0;
  for (LL i = 0; i < tsz; ++i) {
    if (i < nsz) {
      if (tData[tsz - 1 - i] - carry < nData[nsz - 1 - i]) {
        res[tsz - i - 1] =
            (TSTORAGE_SZ + tData[tsz - 1 - i]) - nData[nsz - 1 - i] - carry;
        carry = 1;
      } else
        res[tsz - i - 1] = tData[tsz - 1 - i] - nData[nsz - 1 - i] - carry;
    }
    else{
        res[tsz - i - 1] = tData[tsz - 1 - i] - carry;
        carry = 0;
    }
  }
  return bigint(res);
}