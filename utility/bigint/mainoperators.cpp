#include "main.h"

inline bigint& utility::bigint::operator=(const bigint& n) {
  this->data = bigint::simplify(n).data;
  this->sign = n.getSign();
}

bigint utility::bigint::operator+(const bigint& n) const {
    bigint res{0LL};
    std::vector<TStorage> nData = n.getData();
    if(nData.size() > this->data.size()){
        return n + *this;
    }
    // Current number has more digits for sure
    
}