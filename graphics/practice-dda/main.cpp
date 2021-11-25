#include <iostream>
#include <graphics.h>
#include <cmath>
#include <math.h>
#include <conio.h>

using namespace std;

void dda(int x1, int y1, int x2, int y2)
{
    int dx = abs(x1-x2);
    int dy = abs(y1-y2);
    int step = 0;

    if (dx >= dy)
        step = dx;
    else
        step = dy;

    // Incrementing x and y
    float inc_x = (float)dx/step;
    float inc_y = (float)dy/step;

    // Starting pixel
    float x = x1 + 0.5;
    float y = y1 + 0.5;

    // Drawing
    for (int i = 0; i <= step; i++)
    {
        putpixel(round(x), round(y), YELLOW);
        x += inc_x;
        y += inc_y;
    }
}

int main()
{
    int gdriver = DETECT, gm;
    initgraph(&gdriver, &gm, "");
    int x1, y1, x2, y2;
    printf("Enter start coordinates: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter end coordinates: ");
    scanf("%d %d", &x2, &y2);
    dda(x1, y1, x2, y2);
    _getch();
    closegraph();
    return 0;
}
