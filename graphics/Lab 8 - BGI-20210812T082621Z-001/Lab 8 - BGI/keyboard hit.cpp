#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
#include<dos.h>
#include<string.h>
#include<iostream>
#include<ctime>



#define S_N_L (radius-10)        // Second Needle Length
#define S_N_C RED                   // Second needle Color
#define M_N_L (radius-20)           // Minute Needle Length
#define M_N_C LIGHTRED              // Minute Needle Color
#define H_N_L (radius-(radius/2))       // Hour Needle Length
#define H_N_C CYAN                     // Hour Needle Color

int main(void)
{
    /* request auto detection */
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");
    /***********************************/


    setcolor(14);
    rectangle(50,50,150,150);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(51,51,14);

    setcolor(14);
    rectangle(160,50,260,150);

    while (1) {
        if (kbhit()) {
            char c= getch();
            printf("input %d\n",c);
            if (c==77) {
                setfillstyle(SOLID_FILL,BLACK);
                floodfill(51,51,14);
                setfillstyle(SOLID_FILL,GREEN);
                floodfill(161,51,14);
            }
        }
    }


    getch();
    closegraph();
    return 0;

}
