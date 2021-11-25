#include <iostream>
#include <conio.h>
#include <math.h>
#include <cmath>
#include <graphics.h>

using namespace std;

void bres(int x1, int y1, int x2, int y2)
{
    float p = 2*(y2-y1) - (x2-x1);
    for (int x = x1, y = y1; x <= x2; x++)
    {
        if (p >= 0)
        {
            putpixel(x, y, WHITE);
            y++;
            p += (2*(y2-y1) - 2*(x2-x1));
        }
        else
        {
            putpixel(x, y, WHITE);
            p += (2*(y2-y1));
        }
    }
}

int main()
{
    int gdriver = DETECT, gm;
    initgraph(&gdriver, &gm, "");
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    bres(x1, y1, x2, y2);
    _getch();
    closegraph();
    return 0;
}
