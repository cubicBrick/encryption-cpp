#include "main.h"

bool utility::bigint::toLL(utility::LL &out) const {
    out = 0;
    utility::LL curr = 1;
    for(LL i = this->data.size() - 1; i >= 1; --i){
        if(curr > std::numeric_limits<utility::LL>::max()) return false;
        utility::LL op = out;
        out += curr * this->data[i];
        if(out < op){
            return false;
        }
        curr *= TSTORAGE_SZ;
    }
    return true;
}

utility::bigint utility::bigint::simplify(const bigint &n) {
    return bigint(simplify(n.getData()), n.getSign());
}

std::vector<utility::TStorage> utility::bigint::simplify(
    std::vector<utility::TStorage> n) {
  bool has = false;
  std::vector<utility::TStorage>::iterator itend = n.begin();
  for (auto it = n.begin(); it < n.end(); ++it) {
    if (*it == 0) {
      if (!has)
        has = true;
      else
        ++itend;
    }
  }
  n.erase(n.begin(), itend);
  return n;
}
