// animate1 --- create animation using img lib.
#include "img.h"

int main(void) {
  struct color c1 = { 0, 0,100 };
  struct color c2 = { 255, 0, 0 };
  int i;
  int easing = 0;
  for(i = 20; i > 0; --i) {
    easing = i*i*i/20;
    img_clear(); img_fillu(c1, 100+easing, 85, 20);img_fille(c1, 150+easing, 85, 20);img_fillc(c1, 197+easing,85, 20); img_write();
  }
  for(i = 0; i < 20; ++i) {
    img_clear(); img_fillu(c1, 100, 85, 20);img_fille(c1, 150, 85, 20);img_fillc(c1, 197,85, 20); img_write();
  }
  for(i = 0; i < 20; ++i) {
    easing = -i*i*i/20;
    img_clear(); img_fillu(c1, 100+easing, 85, 20);img_fille(c1, 150+easing, 85, 20);img_fillc(c1, 197+easing,85, 20); img_write();
  }
  return 0;
}
