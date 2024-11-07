#include "main.h"

bool utility::bigint::operator==(bigint n) const {
  if (n.getSign() != this->sign) return false;
  if (n.getData().size() != this->data.size()) return false;
  for (LL i = 0; i < this->data.size(); ++i) {
    if (this->data[i] != n.getData()[i]) {
      return false;
    }
  }
  return true;
}

bool utility::bigint::operator>(const bigint& n) const {
  if (n.getSign() && !this->sign) return false;
  if (!n.getSign() && this->sign) return true;
  if (!n.getSign() && !this->sign) return !(-*this > -n);
  if (n.getData().size() > this->data.size()) return false;
  if (n.getData().size() < this->data.size()) return true;
  for (LL i = 0; i < this->data.size(); ++i) {
    if (this->data[i] > n.getData()[i]) {
      return true;
    }
  }
  return false;
}
