#include <stdio.h>
#include <graphics.h>

void dda_line(int x1, int y1, int x2, int y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float x_increment = dx / step;
    float y_increment = dy / step;

    float x = x1, y = y1;
    putpixel(x, y, WHITE);

    for (int i=0; i<step; i++) {
        x += x_increment;
        y += y_increment;
        putpixel(round(x), round(y), WHITE);  // 四舍五入取整
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 50, y1 = 100, x2 = 250, y2 = 400;
    dda_line(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

