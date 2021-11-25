#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <cmath>

using namespace std;

void mpe(int xc, int yc, int a, int b)
{
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = b;

    d1 = (b*b) - (a*a*b) + (0.25*a*a);
    dx = 2*b*b*x;
    dy = 2*a*a*y;

    while (dx < dy)
    {
        putpixel(x+xc, y+yc, RED);
        putpixel(-x+xc, y+yc, RED);
        putpixel(x+xc, -y+yc, RED);
        putpixel(-x+xc, -y+yc, RED);

        if (d1 < 0)
        {
            x++;
            dx = dx + (2*b*b);
            d1 = d1 + dx + (b*b);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2*b*b);
            dy = dy - (2*a*a);
            d1 = d1 + dx - dy + (b*b);
        }
    }

    d2 = ((b*b)*((x+0.5)*(x+0.5)))+((a*a)*((y-1)*(y-1)))-(a*a*b*b);

    while (y >= 0)
    {
        putpixel(x+xc, y+yc, RED);
        putpixel(-x+xc, y+yc, RED);
        putpixel(x+xc, -y+yc, RED);
        putpixel(-x+xc, -y+yc, RED);

        if (d2 > 0)
        {
            y--;
            dy = dy-(2*a*a);
            d2 = d2 + (a*a) - dy;
        }
        else
        {
            x++;
            y--;
            dx = dx + (2*b*b);
            dy = dy - (2*a*a);
            d2 = d2 + dx - dy + (a*a);
        }
    }
}

int main()
{
    int gdriver = DETECT, gm;
    initgraph(&gdriver, &gm, "");
    int x, y, a, b;
    scanf("%d %d %d %d", &x, &y, &a, &b);
    mpe(x, y, a, b);
    _getch();
    closegraph();
    return 0;
}
