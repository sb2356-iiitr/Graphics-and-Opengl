/* Program implementing Midpoint Ellipse
 Drawing algorithm */

#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <cmath>
#include <math.h>

using namespace std;

void ellipse(int xc, int yc, int a, int b)
{
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = b;

    d1 = (b * b) - (a * a * b) + (0.25 * a * a);
    dx = 2 * b * b * x;
    dy = 2 * a * a * y;

    while (dx < dy)
    {
        putpixel(x + xc, y + yc, RED);
        putpixel(-x + xc, y + yc, WHITE);
        putpixel(x + xc, -y + yc, YELLOW);
        putpixel(-x + xc, -y + yc, GREEN);

        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * b * b);
            d1 = d1 + dx + (b * b);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * b * b);
            dy = dy - (2 * a * a);
            d1 = d1 + dx - dy + (b * b);
        }
    }

    d2 = ((b * b) * ((x + 0.5) * (x + 0.5))) + ((a * a) * ((y - 1) * (y - 1))) - (a * a * b * b);

    while (y >= 0)
    {
        putpixel(x + xc, y + yc, RED);
        putpixel(-x + xc, y + yc, WHITE);
        putpixel(x + xc, -y + yc, YELLOW);
        putpixel(-x + xc, -y + yc, GREEN);

        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * a * a);
            d2 = d2 + (a * a) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * b * b);
            dy = dy - (2 * a * a);
            d2 = d2 + dx - dy + (a * a);
        }
    }
}

int main()
{
    int gdriver = DETECT, gm;
    initgraph(&gdriver, &gm, "");
    int x, y, a, b;
    printf("Enter x and y coordinates of center: ");
    scanf("%d %d", &x, &y);
    printf("Enter axis A: ");
    scanf("%d", &a);
    printf("Enter axis B: ");
    scanf("%d", &b);
    ellipse(x, y, a, b);
    _getch();
    closegraph();
    return 0;
}
