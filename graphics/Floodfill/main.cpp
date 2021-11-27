#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

void floodFill(int, int, int, int); // First 2 for pixel positon, 3rd for filling color, 4th for color (boundary/surface)

int main()
{
    int gdriver = DETECT, gm;
    initgraph(&gdriver, &gm, "");

    int x = 150, y = 180; //seed point inside triangle

    line(100, 200, 150, 150);
    setcolor(YELLOW);
    line(150, 150, 200, 200);
    setcolor(GREEN);
    line(200, 200, 100, 200);

    floodFill(x, y, GREEN, BLACK);

    _getch();
    closegraph();
    return 0;
}

void floodFill(int x, int y, int fcolor, int icolor)
{
    int color;
    // Set current color to fillColor, then perform following operations
    color = getpixel(x, y);

    if((color == icolor) && (color != fcolor))
    {
        putpixel(x, y, RED);
        floodFill(x+1, y, fcolor, icolor);
        floodFill(x-1, y, fcolor, icolor);
        floodFill(x, y-1, fcolor, icolor);
        floodFill(x, y+1, fcolor, icolor);
    }

}
