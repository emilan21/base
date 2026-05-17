#include "base/base.h"

string8 str8_substr(string8 str, u64 start, u64 end) {
  end = MIN(end, str.size);
  start = MIN(start, end);

  return (string8){str.str + start, end - start};
}
