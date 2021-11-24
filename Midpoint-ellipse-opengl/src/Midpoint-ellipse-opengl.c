#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
int rx, ry, xc, yc;

void FourWaySymmetricPlot(int x0, int y0, int x, int y)
{
    glVertex2i(x + x0, y + y0);
    glVertex2i(x + x0, -1 * y + y0);
    glVertex2i(-1 * x + x0, -1 * y + y0);
    glVertex2i(-1 * x + x0, y + y0);
}


// function to initialize
void myInit (void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-780, 780, -420, 420);
}

void display ()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;
 
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;
 
    while (dx < dy) {
        FourWaySymmetricPlot(xc, yc, x, y);
        if (d1 < 0) {
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else {
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
        x++;
    }


    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
    while (y >= 0) {
        FourWaySymmetricPlot(xc, yc, x, y);
        if (d2 > 0) {
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else {
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
        y--;
    }

	glEnd();
	glFlush();
}

int main (int argc, char** argv)
{
   
   
    printf("Enter major and minor radius of ellipse:");
    scanf("%d %d", &rx, &ry);
    printf("Enter center of ellipse:");
    scanf("%d %d", &xc, &yc);


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	// giving window size in X- and Y- direction
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	
	// Giving name to window
	glutCreateWindow("Mid Point Ellipse Drawing Algo with OpenGL");
	myInit();
	
	glutDisplayFunc(display);
	glutMainLoop();
    return 0;
}
