#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include<stdio.h>

int x0,y0,x1,y1;

void My_display(void)
{
    float x, y,dx,dy,steps;
    int i;

    dx = (float)(x1 - x0); // (300-100)=200
    dy = (float)(y1 - y0); //(200-100) = 100

    if(dx>dy)
        steps = dx;
    else
        steps = dy;

    dx = dx/steps;
    dy = dy/steps;
        x = x0 + 0.5; //First position I need to draw
        y = y0 + 0.5;
        i = 1;

    glBegin(GL_POINT);
        glVertex2f(x,y);
    glEnd();

    glBegin(GL_POINTS);
    while(i<=steps)
    {
        glVertex2f(x,y);
        x = x +dx;
        y = y +dy;
        i= i+1;
    }
    glEnd();

    glFlush();
}

void init()
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0, 1.0, 1.0, 0.0);//set the background color
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char *argv[])
{
    printf("\n enter the starting points ");
    scanf("%d%d",&x0,&y0);
    printf("\n enter the ending points ");
    scanf("%d%d",&x1,&y1);

    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB);

    glutCreateWindow("This is my first openGL program");

    init();

    glutDisplayFunc(My_display); //callback function

    glutMainLoop();
    return EXIT_SUCCESS;
}
