#include "animation.h"
#include "img.h"


int main(void) {
  for (int f = 0; f < 80; f++) {
    img_clear();
    draw_bg(f);
    draw_fg(f);
    img_write();
  }

  return 0;
}
