/* Program implementing Bresenham line drawing
algorithm */


#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <cmath>
#include <math.h>

using namespace std;

void bresenham(int x1, int y1, int x2, int y2)
{
    float p = 2*(y2-y1) - (x2-x1);
    for (int x = x1, y = y1; x <= x2; x++)
    {
        printf("%d %d\n", x, y);
        if(p >= 0)
        {
            putpixel(x, y, WHITE);
            y++;
            p += (2*(y2-y1) - 2*(x2-x1));
        }
        else
        {
            putpixel(x, y, WHITE);
            p += 2*(y2-y1);
        }

    }
}

int main()
{
    int gdriver = DETECT, gm;
    initgraph(&gdriver, &gm, "");
    int x1, y1, x2, y2;
    printf("Enter start coordinates: \n");
    scanf("%d %d", &x1, &y1);
    printf("Enter end coordinates: \n");
    scanf("%d %d", &x2, &y2);
    bresenham(x1, y1, x2, y2);
    _getch();
    closegraph();
    return 0;
}
