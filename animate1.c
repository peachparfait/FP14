// animate1 --- create animation using img lib.
#include "img.h"

int main(void) {
  struct color c1 = { 30, 255, 0 };
  struct color c2 = { 255, 0, 0 };
  int i;
  for(i = 0; i < 20; ++i) {
    img_clear(); img_fillu(c1, 100, 85, 20);img_fille(c1, 150, 85, 20);img_fillc(c1, 197,85, 20); img_write();
  }
  return 0;
}
