#include "img.h"

void draw_bg(int f) {
  struct color c1 = { 255, 153, 153 };
  struct color c2 = { 255, 255, 153 };
  struct color c3 = { 153, 255, 153 };
  struct color c4 = { 153, 255, 255 };
  struct color c5 = { 153, 153, 255 };
  struct color c6 = { 255, 153, 255 };

  int x = f * 10;
  img_fillcircle(c1, x, 34, 10); 
  img_fillcircle(c1, x, 122, 10); 
  img_fillcircle(c2, x-44, 78, 10); 
  img_fillcircle(c2, x-44, 166, 10); 
  img_fillcircle(c3, x-88, 34, 10); 
  img_fillcircle(c3, x-88, 122, 10); 
  img_fillcircle(c4, x-132, 78, 10); 
  img_fillcircle(c4, x-132, 166, 10); 
  img_fillcircle(c5, x-176, 34, 10); 
  img_fillcircle(c5, x-176, 122, 10);
  img_fillcircle(c6, x-220, 78, 10); 
  img_fillcircle(c6, x-220, 166, 10);
  img_fillcircle(c1, x-264, 34, 10); 
  img_fillcircle(c1, x-264, 122, 10); 
  img_fillcircle(c2, x-308, 78, 10); 
  img_fillcircle(c2, x-308, 166, 10); 
  img_fillcircle(c3, x-352, 34, 10); 
  img_fillcircle(c3, x-352, 122, 10); 
  img_fillcircle(c4, x-396, 78, 10);  
  img_fillcircle(c4, x-396, 166, 10); 
  img_fillcircle(c5, x-440, 34, 10); 
  img_fillcircle(c5, x-440, 122, 10); 
  img_fillcircle(c6, x-484, 78, 10); 
  img_fillcircle(c6, x-484, 166, 10);
  img_fillcircle(c1, x-528, 34, 10); 
  img_fillcircle(c1, x-528, 122, 10); 
  img_fillcircle(c2, x-572, 78, 10); 
  img_fillcircle(c2, x-572, 166, 10); 
  img_fillcircle(c3, x-616, 34, 10); 
  img_fillcircle(c3, x-616, 122, 10); 
  img_fillcircle(c4, x-660, 78, 10);  
  img_fillcircle(c4, x-660, 166, 10); 
  img_fillcircle(c5, x-704, 34, 10); 
  img_fillcircle(c5, x-704, 122, 10);
}
