#include <GL/glut.h>
#include <stdio.h>

int x, y, r;

void draw(x, y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void cir(int x, int y, int r)
{
    
}

void disp()
{
    cir(x, y, r);
    glFlush();
}

void myInit()
{
    glClear(GL_COLOR_BUFFET_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.1);
    glMatrixMode(GL_PRODUCTION);
    glOrtho2d(0, 700, 0, 700);
}

void main(int argc, char **argv)
{
    scanf("%d %d %d", &x, &y, &r);
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutWindowSize(700, 700);
    glutWindowPosition(20, 20);
    glutCreateWindow("Midpoint");
    myInit();
    glutDisplayFunc(disp);
    glutMainLoop();
}
