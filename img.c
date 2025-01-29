#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "img.h"

static unsigned char buf[HEIGHT][WIDTH][3];
static int filecnt = 0;
static char fname[100];

void img_clear(void) {
  int i, j;
  for(j = 0; j < HEIGHT; ++j) {
    for(i = 0; i < WIDTH; ++i) {
      buf[j][i][0] = buf[j][i][1] = buf[j][i][2] = 255;
    }
  }
}

void img_write(void) {
  sprintf(fname, "img%04d.ppm", ++filecnt);
  FILE *f = fopen(fname, "wb");
  if(f == NULL) { fprintf(stderr, "can't open %s\n", fname); exit(1); }
  fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
  fwrite(buf, sizeof(buf), 1, f);
  fclose(f);
}

void img_putpixel(struct color c, int x, int y) {
  if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) { return; }
  buf[HEIGHT-y-1][x][0] = c.r;
  buf[HEIGHT-y-1][x][1] = c.g;
  buf[HEIGHT-y-1][x][2] = c.b;
}

void img_fillcircle(struct color c, double x, double y, double r) {
  int imin = (int)(x - r - 1), imax = (int)(x + r + 1);
  int jmin = (int)(y - r - 1), jmax = (int)(y + r + 1);
  int i, j;
  for(j = jmin; j <= jmax; ++j) {
    for(i = imin; i <= imax; ++i) {
      if((x-i)*(x-i) + (y-j)*(y-j) <= r*r) { img_putpixel(c, i, j); }
    }
  }
}

void img_fillu(struct color c, double x, double y, double r) {
  int imin = (int)(x - r - 1), imax = (int)(x + r + 1);
  int jmin = (int)(y - r - 1), jmax = (int)(y + r + 1);
  int i, j;
  for(j = jmin; j <= jmax; ++j) {
    for(i = imin; i <= imax; ++i) {
      if(((x-i)*(x-i)+(y-j+r/2)*(y-j+r/2))<=r*r && ((x-i)*(x-i)+(y-j+r/2)*(y-j+r/2))>=(r*r/2) && y-j>=(-r/2)) { img_putpixel(c, i, j); }
      if((x-i)>=sqrt(r*r/2) && (x-i)<=r && y-j<=r/2 && y-j>=-r) { img_putpixel(c, i, j+r); }
      if((x-i)<=-sqrt(r*r/2) && (x-i)>=-r && y-j<=r/2 && y-j>=-r) { img_putpixel(c, i, j+r); }
    }
  }
}
void img_fille(struct color c, double x, double y, double r) {
  int imin = (int)(x - r - 1), imax = (int)(x + r + 1);
  int jmin = (int)(y - r - 1), jmax = (int)(y + 2*r + 1);
  int i, j;
  for(j = jmin; j <= jmax; ++j) {
    for(i = imin; i <= imax; ++i) {
      if((x-i)>=sqrt(r*r/2) && (x-i)<=r && y-j<=r/5*2 && y-j>=-r*2) { img_putpixel(c, i, j); }
      if((x-i)>=-r*0.8 && (x-i)<=r && y-j<=-r*2+r-sqrt(r*r/2) && y-j>=-r*2) { img_putpixel(c, i, j); }
      if((x-i)>=-r*0.8 && (x-i)<=r && y-j>=r/5*2-r+sqrt(r*r/2) && y-j<=r/5*2) { img_putpixel(c, i, j); }
      if((x-i)>=-r*0.8 && (x-i)<=r && y-j<=r/10-sqrt(r*r/2) && y-j>=-r+r/10) { img_putpixel(c, i, j); }
    }
  }
}
void img_fillc(struct color c, double x, double y, double r) {
  int imin = (int)(x - r - 1), imax = (int)(x + r + 1);
  int jmin = (int)(y - r - 1), jmax = (int)(y + 2*r + 1);
  int i, j;
  for(j = jmin; j <= jmax; ++j) {
    for(i = imin; i <= imax; ++i) {
      if(((2.0/3.0)*(x-i+r/8)*(x-i+r/8)+(2.0/3.0)*(y-j+r-r/4)*(y-j+r-r/4))<=r*r && ((2.0/3.0)*(x-i+r/8)*(x-i+r/8)+(2.0/3.0)*(y-j+r-r/4)*(y-j+r-r/4))>=(r*r/1.8) &&(x-i)>=-sqrt(r*r/2)) { img_putpixel(c, i, j); }
    }
  }
}
void img_fillrec(struct color c, double x, double y, double r) {
  int imin = (int)(x - r - 1), imax = (int)(x + r + 1);
  int jmin = (int)(y - r - 1), jmax = (int)(y + 2*r + 1);
  int i, j;
  for(j = jmin; j <= jmax; ++j) {
    for(i = imin; i <= imax; ++i) {
      if((x-i)>=-r*0.8 && (x-i)<=r && y-j<=-r*2+r/8 && y-j>=-r*2) { img_putpixel(c, i, j); }
    }
  }
}
