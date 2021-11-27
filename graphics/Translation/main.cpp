#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <iostream>

int n, xs[100], ys[100], i, tx, ty;
// tx and ty are translation factors along x and y respectively.

void draw();
void translate();

int main()
{
    int gdriver = DETECT, gm;

    printf("No. of Sides of Polygon: ");
    scanf("%d", &n);
    printf("Enter coordinates of vertices: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &xs[i], &ys[i]);
    }
    printf("Enter distances for translation: ");
    scanf("%d %d", &tx, &ty);
    initgraph(&gdriver, &gm, "");
    //drawing original polygon in RED color
    setcolor(RED);
    draw();
    //Translation
    translate();
    //drawing translated polygon
    setcolor(YELLOW);
    draw();
    _getch();
    closegraph();

    return 0;
}

void draw()
{
    for(i=0; i<n; i++)
        line(xs[i], ys[i], xs[(i+1)%n], ys[(i+1)%n]);
}

void translate()
{
    for(i=0; i<n; i++)
    {
        xs[i]+=tx;
        ys[i]+=ty;
    }
}
