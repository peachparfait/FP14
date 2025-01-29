// animate1 --- create animation using img lib.
#include "img.h"

void draw_fg(int f) {
  struct color c1 = { 0, 0,100 };
  struct color c2 = { 255, 0, 0 };
  int i;
  int half;
  int easing = 0;
  if (f < 20) {
    i = 20 - f;
    easing = i*i*i/20;
    img_fillu(c1, 100+easing, 85, 20);img_fille(c1, 150+easing, 85, 20);img_fillc(c1, 197+easing,85, 20);
  } else if (f < 60) {
    i = f - 20;
    half=i/2;
    easing = 250-half*half*half/10;
    img_fillu(c1, 100, 85, 20);img_fille(c1, 150, 85, 20);img_fillc(c1, 197,85, 20);
    img_fillrec(c1, 155+easing,-50, 100); img_fillrec(c1, 155-easing,-138, 100);
  } else {
    i = f - 60;
    easing = -i*i*i/20;
    img_fillu(c1, 100+easing, 85, 20);img_fille(c1, 150+easing, 85, 20);img_fillc(c1, 197+easing,85, 20);
  }
}
