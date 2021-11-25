#include <iostream>
#include <math.h>
#include <cmath>
#include <conio.h>
#include <graphics.h>

using namespace std;

void mp(int x, int y, int r)
{
    int xk = r, yk = 0, err = 0;

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

        if(err <= 0)
        {
            yk += 1;
            err += (2*yk + 1);
        }

        if(err > 0)
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
    scanf("%d %d %d", &x, &y, &r);
    mp(x, y, r);
    _getch();
    closegraph();
    return 0;
}
