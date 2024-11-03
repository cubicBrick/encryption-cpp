#include <limits>
#pragma once

namespace utility {
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int TStorage;
constexpr LL BASE = std::numeric_limits<TStorage>::max();
};  // namespace utility