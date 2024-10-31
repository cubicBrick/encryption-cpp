#include <utility/type.h>
#include <string>
namespace utility {
class bigint {
 private:
 // Stored as list of bytes, least significant at back
 std::string data;
 // sign
 bool positive;

 public:
  bigint(LL n);
  ~bigint();

};
};  // namespace utility