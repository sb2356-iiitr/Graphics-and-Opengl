#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <cmath>

using namespace std;
int n, x[100], y[100], i;
float sfx, sfy;

void draw();
void scale();

int main()
{
    int gd = DETECT, gm;
    printf("Enter no. of sides: ");
    scanf("%d", &n);
    printf("Enter coordinates: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }

    printf("Enter respective scaling factors: ");
    scanf("%f %f", &sfx, &sfy);
    initgraph(&gd, &gm, "");
    cleardevice();
    setcolor(RED);
    draw();
    scale();
    setcolor(YELLOW);
    draw();
    _getch();
    closegraph();
    return 0;
}

void draw()
{
    for (i = 0; i < n; i++)
        line(x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
}

void scale()
{
    for(i=0; i<n; i++)
    {
        x[i] = x[0]+(int)((float)(x[i]-x[0])*sfx);
        y[i] = y[0]+(int)((float)(y[i]-y[0])*sfy);
    }
}




