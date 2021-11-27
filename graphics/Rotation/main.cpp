#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <cmath>

using namespace std;

int n, x[100], y[100], maxx, maxy, midx, midy, angle;
float a;

void draw();
void rotat();

int main()
{
    int gd = DETECT, gm;
    printf("Enter no of sides: ");
    scanf("%d", &n);
    printf("Enter coordinates of vertices: ");
    for (int i = 0; i<n; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }
    printf("Enter angle in degrees: ");
    scanf("%d", &angle);
    a = (float)angle*(3.14/100);
    initgraph(&gd, &gm, "");
    // Coordinate Axes
    maxx = getmaxx();
    maxy = getmaxy();
    midx = maxx/2;
    midy = maxy/2;
    line(0, midy, maxx, midy);
    line(midx, 0, midx, maxy);

    setcolor(YELLOW);
    draw();
    rotat();
    setcolor(RED);
    draw();

    _getch();
    closegraph();
    return 0;
}

void draw()
{
    for(int i = 0; i < n; i++)
    {
        line(x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
    }
}

void rotat()
{
    for(int i = 0; i < n; i++)
    {
        x[i] = (int)((float)(x[i])*cos(a) - (float)(y[i])*sin(a));
        y[i] = (int)((float)(x[i])*sin(a) + (float)(y[i])*sin(a));
    }
}






