#include "main.h"

bool utility::bigint::toLL(utility::LL &out) const {
    out = 0;
    utility::LL curr = 1;
    for(LL i = this->data.size() - 1; i >= 1; --i){
        if(curr > std::numeric_limits<utility::LL>::max() / TSTORAGE_SZ) return false;
        utility::LL op = out;
        out += curr * this->data[i];
        if(out < op){
            return false;
        }
    }
    return true;
}