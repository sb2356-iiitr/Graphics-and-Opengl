#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

using namespace std;

static int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8, xmin, ymin, xmax, ymax;

int getcode(int x, int y)
{
    int code = 0;
    if (y>ymax) code |= TOP;
    if (y<ymin) code |= BOTTOM;
    if (x<xmin) code |= LEFT;
    if (x>xmax) code |= RIGHT;
    return code;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    setcolor(WHITE);
    /*cout << "Enter windows min and max values: ";
    cin >> xmin >> ymin >> xmax >> xmin;
    line(xmin, ymin, xmax, ymax);
    line(xmax, ymin, xmax, ymax);
    line(xmin, ymin, xmin, ymax);
    line(xmin, ymax, xmax, ymax);*/
    //rectangle(xmin, ymin, xmax, ymax);
    line(200, 200, 350, 200);
     line(350, 200, 350, 350);
     line(200, 200, 200, 350);
     line(200, 350, 350, 350);
     xmin = 200;
     ymin = 200;
     xmax = 350;
     ymax = 350;
    int x1, y1, x2, y2;
    cout << "Enter endpoints of line: ";
    cin >> x1 >> y1 >> x2 >> y2;
    line(x1, y1, x2, y2);

    _getch();

    int outcode1 = getcode(x1, y1), outcode2 = getcode(x2, y2);
    int accept = 0;

    while(1)
    {
        float m = (float)(y2-y1)/(x2-x1);
        if(outcode1 == 0 && outcode2 == 0)
        {
            accept = 1;
            break;
        }
        else if((outcode1&outcode2)!=0)
            break;
        else
        {
            int x, y, temp;
            if (outcode1 == 0)
                temp = outcode2;
            else
                temp = outcode1;

            if(temp&TOP)
            {
                x = x1+(ymax-y1)/m;
                y = ymax;
            }
            else if(temp&BOTTOM)
            {
                x = x1+(ymin-y1)/m;
                y = ymin;
            }
            else if(temp&LEFT)
            {
                y = y1+(xmin-x1)*m;
                x = xmin;
            }
            else if(temp&RIGHT)
            {
                y = y1+(xmax-x1)*m;
                x = xmax;
            }


            if(temp == outcode1)
            {
                x1 = x;
                y1 = y;
                outcode1=getcode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                outcode2=getcode(x2, y2);
            }
        }
    }
    cout << "after clipping";
    if(accept)
    {
        cleardevice();
        line(200, 200, 350, 200);
         line(350, 200, 350, 350);
         line(200, 200, 200, 350);
         line(200, 350, 350, 350);
        setcolor(CYAN);
        line(x1, y1, x2, y2);
    }
    _getch();
    closegraph();
    return 0;
}
