#include <limits.h>
#include <stdint.h>
#include <mruby.h>

uint8_t
clamp_u8(mrb_int i)
{
  if (i > UINT8_MAX) {
    return UINT8_MAX;
  } else if (i < 0) {
    return 0;
  } else {
    return i;
  }
}

int
clamp_int(mrb_int i)
{
  if (sizeof(int) <= sizeof(mrb_int)) {
  	return i;
  } else {
    if (i > INT_MAX) {
      return INT_MAX;
    } else if (i < INT_MIN) {
      return INT_MIN;
    } else {
      return i;
    }
  }
}
