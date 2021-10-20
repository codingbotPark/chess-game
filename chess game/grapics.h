#include "windowconsole.h"
#define RETX(x) 136 + (x - 1) * 30;
#define RETY(y) 116 - (y - 1) * 15;
#define RETCOLOR(x,y) x % 2 ^ y % 2 ? WHITE : GRAY


void grapicDraw();

void drawVer(int, int, int);
void drawHor(int, int, int);

void drawCore(int, int);

void drawBorder(int, int, char);