#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <stdio.h>

using namespace std;

int main()
{
    int gdriver = DETECT, gm;
    initgraph(&gdriver, &gm, "");
    circle(250, 250, 50);
    int border_color = WHITE;
    //floodfill(250, 250, border_color); //Fill whole area.
    //Fill with pattern
    //setfillstyle(int pattern, int color)
    setfillstyle(HATCH_FILL, WHITE);
    floodfill(250, 250, WHITE);

    setlinestyle(3, 4, 4);
    line(1, 1, 100, 100);
    getch();
}
