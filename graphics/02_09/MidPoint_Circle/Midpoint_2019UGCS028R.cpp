#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <cmath>
#include <math.h>

using namespace std;

void midpoint(int x, int y, int r)
{
    int xk = r;
    int yk = 0;
    int err = 0;

    while (xk >= yk)
    {
        putpixel(x+xk, y+yk, YELLOW);
        putpixel(x+yk, y+xk, YELLOW);
        putpixel(x-yk, y+xk, YELLOW);
        putpixel(x-xk, y+yk, YELLOW);
        putpixel(x-xk, y-yk, YELLOW);
        putpixel(x-yk, y-xk, YELLOW);
        putpixel(x+yk, y-xk, YELLOW);
        putpixel(x+xk, y-yk, YELLOW);

        if (err <= 0)
        {
            yk += 1;
            err += (2*yk + 1);
        }

        if (err > 0)
        {
            xk -= 1;
            err -= (2*xk + 1);
        }
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
    midpoint(x, y, r);
    _getch();
    closegraph();
    return 0;
}
