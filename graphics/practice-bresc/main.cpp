#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <cmath>
#include <math.h>

using namespace std;

void drawcircle(int x0, int y0, int x, int y)
{
    putpixel(x0+x, y0+y, RED);
    putpixel(x0-x, y0+y, RED);
    putpixel(x0+x, y0-y, RED);
    putpixel(x0-x, y0-y, RED);
    putpixel(x0+y, y0+x, RED);
    putpixel(x0-y, y0+x, RED);
    putpixel(x0+y, y0-x, RED);
    putpixel(x0-y, y0-x, RED);
}

void bresenham(int x0, int y0, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawcircle(x0, y0, x, y);
    while (y >= x)
    {
        if (d>0)
        {
            y--;
            d = d + 4 * (x-y) + 10;
        }
        else
            d = d + 4 * x + 6;
        x++;
        drawcircle(x0, y0, x, y);
    }
}

int main()
{
    int gdriver = DETECT, gm;
    initgraph(&gdriver, &gm, "");
    int x, y, r;
    printf("Enter x and y coordinates of center: ");
    scanf("%d %d", &x, &y);
    printf("Enter radius: ");
    scanf("%d", &r);
    bresenham(x, y, r);
    _getch();
    closegraph();
    return 0;
}
