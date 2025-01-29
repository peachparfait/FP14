#define WIDTH 300
#define HEIGHT 200
struct color { unsigned char r, g, b; };
void img_clear(void);
void img_write(void);
void img_putpixel(struct color c, int x, int y);
void img_fillcircle(struct color c, double x, double y, double r);
void img_fillu(struct color c, double x, double y, double r);
void img_fille(struct color c, double x, double y, double r);
void img_fillc(struct color c, double x, double y, double r);
void img_fillrec(struct color c, double x, double y, double r);